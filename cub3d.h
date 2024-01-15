/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:39 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/15 19:01:12 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# define EMPTY '0'
# define WALL '1'

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MIN_WIDTH 500
# define MIN_HEIGHT 500
# define FOV (M_PI / 2)

typedef struct s_data		t_data;
typedef struct s_textures	t_textures;

typedef struct s_game
{
	t_textures	*textures;
	t_data		*data;
	t_ray		*ray;
	t_player	*player;
	t_column	*pixel_info;
}				t_game;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
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

typedef struct s_column {
	t_pos		wall_hit; // the x;y coordinate when the ray touches a wall
	double		distance; // distance in coordinate plane from x;y to x axis
	char		touched_wall; // side of the wall block the ray has touched
	double		ray_len;
}				t_column;

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

//raycast
void	init_player(t_data *data, t_player player);

#endif