/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:39 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/11 16:04:15 by vnaslund         ###   ########.fr       */
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
void	ft_file_check(t_data *data, char **file, int i);
void	ft_playable_check(t_data *data, char **map);
int		is_first_line_of_file(char *str);
void	player_config_check(t_data *data, char **map);

void	init_explore(t_data *data, int ***visited);
void	explore(t_data *data, int x, int y, int **visited);

void	exit_handler(char *msg, t_data *data);
void	ft_free_array(void **matrix);

#endif