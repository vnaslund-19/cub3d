/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:39 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/19 17:02:33 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

# define EMPTY '0'
# define WALL '1'

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MIN_WIDTH 500
# define MIN_HEIGHT 500

# define FOV (M_PI / 2)
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.05
# define COLLISION_MARGIN 0.25
# define IS_IN_RANGE(value) ((value) >= INT_MIN && (value) <= INT_MAX)

typedef struct s_data		t_data;
typedef struct s_textures	t_textures;
typedef struct s_pos		t_pos;
typedef struct s_ray		t_ray;
typedef struct s_player		t_player;
typedef struct s_column		t_column;

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	*player;
	mlx_image_t	*image;
	t_textures	*textures;
	t_data		*data;
	t_ray		*ray;
	t_column	*pixel_info;
}				t_game;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	int				floor_color;
	int				ceiling_color;
}				t_textures;

typedef struct s_pos {
	double		x;
	double		y;
}				t_pos;

typedef struct s_ray {
	double		ray_angle;
	double		d_angle;
	int			quadrant;
	t_pos		sign;
	t_pos		horizontal;
	t_pos		vertical;
}				t_ray;

typedef struct s_player {
	double		x;
	double		y;
	double		view_angle;
	double		x_viewdir; // vector which depend on view_angle
	double		y_viewdir; // vector which depend on view_angle
}				t_player;

typedef struct 		s_column {
	double			wall_hit; // the x o ry coordinate when the ray touches a wall
	mlx_texture_t	*texture; // texture of the wall block the ray has touched
	double			distance; // distance in perpendicular plane from x;y to x axis
	double			ray_len; // ray length (needed for distance calculations)
}					t_column;

typedef struct s_data
{
	char	**file;
	int		lines;
	char	**map;
	int		rows;
	int		max_cols;
	int		p_position[2];
	int		players;
	char	player_direction;
	bool	allocated_map;
	bool	allocated_file;
	int		rceil;
	int		gceil;
	int		bceil;
	int		rfloor;
	int		gfloor;
	int		bfloor;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		first_line_of_map;
}			t_data;

void	ft_read_file(t_game *game, char **argv);
int		ft_allocate_lines(t_game *game, char **argv);

// Recursively check each line to:
// Find info for floor & ceiling color, & NO, SO, WE & EA textures
// Find the first line of the map
void	ft_file_check(t_game *game, char **file, int i);
int		find_floor_or_ceil(t_data *data, char **file, int i);
int		find_no_or_so(t_game *game, char **file, int i);
int		find_we_or_ea(t_game *game, char **file, int i);
int		is_first_line_of_map(char *str);

void	ft_playable_check(t_game *game, char **map);
void	revise_data(t_game *game);

// Check that there is only one player character and no invalid characters
void	player_config_check(t_game *game, char **map);

// Fill map with spaces to make it a rectangle to prepare for DFS algo
void	ft_fill_map(t_game *game);
void	add_spaces(t_game *game, char **map, int max_cols);

// Depth-First Search algorithm 
// Checks if all possible paths for the player are valid
void	init_explore(t_game *game, int ***visited);
void	explore(t_game *game, int x, int y, int **visited);

// Debugging
void	debug_print_mapinfo(t_data *data);
void	debug_print_visited(int **visited, int rows, int cols);

// Exit and memory handling
void	exit_handler(char *msg, t_game *game);
void	ft_free_array(void **matrix);
void	ft_end_game(t_game *game);

// MLX
void	init_window(t_game *game);
void	load_textures(t_game *game);

void	key_hook(mlx_key_data_t keydata, void *param);
void	loop_hook(void	*param);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate(t_game *game, int angle);

// Raycasting
void	raycast(t_game *game);
void	init_player(t_game *game);
void	draw_floor_and_ceiling(t_game *game);
void	draw_texture(t_game	*game, mlx_texture_t *texture); //test function
void	calc_wall_and_draw(t_game *game, int x);

// Utils
int		get_rgba(int r, int g, int b, int a);
int		get_texture_pixel_color(mlx_texture_t *texture, int y, int x);

//raycasting each column
t_pos		get_first_step(t_player *player, t_ray *ray, double angle, char crossing);
t_pos		get_ray_pos(t_ray *ray, t_game *game, t_pos step, char crossing);
t_column	*ray_caster(t_game *game, int i);
t_column	*init_pixel_column(t_ray *ray, t_game *game, t_pos step, char crossing);

// ray casting utils
double			get_fractional_part(t_pos *hit_point);
mlx_texture_t	*get_rays_texture_extension(t_game *game, t_pos *hit_point, t_ray *ray);
mlx_texture_t	*get_rays_texture(t_game *game, t_pos *hit_point, t_ray *ray);
double			get_absoulte(double ray_angle, double view_angle);
bool			wall_check(t_data *data, t_ray *ray, t_pos step, char crossing);

// getting rays angle and its quadrant
void		init_ray(t_ray *ray, t_player *player, int x);
double		get_ray_angle(double angle, double x);
void		determine_quadrant(t_ray *ray);

#endif