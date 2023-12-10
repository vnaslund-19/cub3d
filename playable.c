/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:38 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/10 16:12:52 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_check(t_data *data, char **map)
{
	int	i;
	int	first_len;
	int	len;

	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len != first_len)
			exit_handler("Map error: not a rectangle", data);
		if (map[i][0] != WALL || map[i][len - 2] != WALL)
			exit_handler("Map error: missing wall", data);
		i++;
	}
	len--;
	data->cols = len;
	while (len--)
	{
		if (!map[0] || map[0][len] != WALL || map[i - 1][len] != WALL)
			exit_handler("Map error: missing wall", data);
	}
	ft_playable_check(data, map);
}

void	ft_playable_check(t_data *data, char **map)
{
	data->players = 0;
	player_config_check(data, map);
	if (data->players != 1)
		exit_handler("Map error: exactly 1 player position needed", data);
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
