/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:39 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/12 16:49:45 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <fcntl.h>

# define EMPTY '0'
# define WALL '1'

typedef struct s_data
{
	char	**file;
	int		lines;
	char	**map;
	int		rows;
	int		max_cols;
	int		p_position[2];
	int		players;
	char	direction;
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

// Check that there is only one player character and no invalid characters
void	player_config_check(t_data *data, char **map);

// Fill map with spaces to make it a rectangle to prepare for DFS algo
void	ft_fill_map(t_data *data);
void	add_spaces(t_data *data, char **map, int max_cols);

// Depth-First Search algorithm 
// Checks if all possible paths for the player are valid
void	init_explore(t_data *data, int ***visited);
void	explore(t_data *data, int x, int y, int **visited);

void	debug_print_visited(int **visited, int rows, int cols);

// Exit and memory handling
void	exit_handler(char *msg, t_data *data);
void	ft_free_array(void **matrix);

#endif