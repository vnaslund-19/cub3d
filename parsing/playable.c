/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:38 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/24 16:35:05 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	valid_color(char **color, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (**color)
	{
		if (!ft_isdigit(**color))
			return (false);
		nb = nb * 10 + (**color - '0');
		(*color)++;
		if (**color == c)
		{
			if (nb < 0 || nb > 255)
				return (false);
			else
				return (true);
		}
	}
	return (false);
}

bool	color_check(char *line)
{
	if (!valid_color(&line, ','))
		return (false);
	line++;
	if (!valid_color(&line, ','))
		return (false);
	line++;
	if (!valid_color(&line, '\n'))
		return (false);
	else
		return (true);
}

void	ft_playable_check(t_game *game, char **map)
{
	int	**visited;

	game->data->players = 0;
	player_config_check(game, map);
	if (game->data->players != 1)
		exit_handler("Map error: exactly 1 player position needed", game);
	init_explore(game, &visited);
	explore(game, game->data->p_position[0], game->data->p_position[1],
		visited);
	ft_free_array((void **)visited);
}

void	player_config_check(t_game *game, char **map)
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
				game->data->players++;
				game->data->p_position[0] = j;
				game->data->p_position[1] = i;
				game->data->player_direction = map[i][j];
			}
			else if (map[i][j] != EMPTY && map[i][j] != ' ' &&
				map[i][j] != WALL && map[i][j] != '\n')
				exit_handler("Map error: Invalid character found", game);
		}
	}
}
