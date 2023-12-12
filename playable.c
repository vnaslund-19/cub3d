/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:38 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/12 14:05:19 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_playable_check(t_data *data, char **map)
{
	int	**visited;

	data->players = 0;
	player_config_check(data, map);
	if (data->players != 1)
		exit_handler("Map error: exactly 1 player position needed", data);
	init_explore(data, &visited);
	explore(data, data->p_position[0], data->p_position[1], visited);
	debug_print_visited(visited, data->rows, data->max_cols);
	ft_free_array((void **)visited);
}

void	player_config_check(t_data *data, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->players++;
				data->p_position[0] = j;
				data->p_position[1] = i;
				data->direction = map[i][j];
			}
			else if (map[i][j] != EMPTY && map[i][j] != ' ' &&
				map[i][j] != WALL && map[i][j] != '\n')
				exit_handler("Map error: Invalid character found", data);
		}
	}
}
