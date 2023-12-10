/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:39 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/10 16:12:25 by vnaslund         ###   ########.fr       */
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
	char	**map;
	int		rows;
	int		cols;
	int		p_position[2];
	int		players;
	char	direction;
	bool	allocated_map;
}			t_data;

void	ft_read_map(t_data *data, char **argv);
int		ft_allocate_lines(t_data *data, char **argv);
void	ft_map_check(t_data *data, char **map);
void	ft_playable_check(t_data *data, char **map);
void	player_config_check(t_data *data, char **map);

void	exit_handler(char *msg, t_data *data);
void	ft_free_matrix(t_data *data, void **matrix);

#endif