/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:39 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/11 11:29:08 by gkrusta          ###   ########.fr       */
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
# define WIDTH 1000
# define HEIGHT 800
# define FOV (M_PI / 2)

typedef struct s_player {
	double		x;
	double		y;
	double		view_angle;
	double		x_viewdir; // vector which depend on view_angle
	double		y_viewdir; // vector which depend on view_angle
	double		ray_angle;
	double 		x_raydir;
	double 		y_raydir;
}				t_player;

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
	//int			mapx; // in which coordinates is playerse current position
	//int			mapy;
	double		rx;
	double		ry;
	bool		hit;
	t_player	pos;
}			t_data;

void	ft_read_file(t_data *data, char **argv);
int		ft_allocate_lines(t_data *data, char **argv);

// Recursively check each line to:
// Find info for floor & ceiling color, & NO, SO, WE & EA textures
// Find the first line of the map
void	ft_file_check(t_data *data, char **file, int i);
int		find_floor_or_ceil(t_data *data, char **file, int i);
int		find_no_or_so(t_data *data, char **file, int i);
int		find_we_or_ea(t_data *data, char **file, int i);
int		is_first_line_of_map(char *str);

void	ft_playable_check(t_data *data, char **map);
void	revise_data(t_data *data);

// Check that there is only one player character and no invalid characters
void	player_config_check(t_data *data, char **map);

// Fill map with spaces to make it a rectangle to prepare for DFS algo
void	ft_fill_map(t_data *data);
void	add_spaces(t_data *data, char **map, int max_cols);

// Depth-First Search algorithm 
// Checks if all possible paths for the player are valid
void	init_explore(t_data *data, int ***visited);
void	explore(t_data *data, int x, int y, int **visited);

// Debugging
void	debug_print_mapinfo(t_data *data);
void	debug_print_visited(int **visited, int rows, int cols);

// Exit and memory handling
void	exit_handler(char *msg, t_data *data);
void	ft_free_array(void **matrix);
void	ft_end_game(t_data *data);


//raycast
void	init_player(t_data *data);

#endif