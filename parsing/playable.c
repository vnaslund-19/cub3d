/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:38 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 18:02:36 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	//debug_print_visited(visited, game->data->rows, game->data->max_cols);
	ft_free_array((void **)visited);
	revise_data(game);
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

void	revise_data(t_game *game)
{
	if (game->data->rfloor > 255 || game->data->rfloor < 0)
		exit_handler("Floor color error", game);
	else if (game->data->gfloor > 255 || game->data->gfloor < 0)
		exit_handler("Floor color error", game);
	else if (game->data->bfloor > 255 || game->data->bfloor < 0)
		exit_handler("Floor color error", game);
	else if (game->data->rceil > 255 || game->data->rceil < 0)
		exit_handler("Ceiling color error", game);
	else if (game->data->gceil > 255 || game->data->gceil < 0)
		exit_handler("Ceiling color error", game);
	else if (game->data->bceil > 255 || game->data->bceil < 0)
		exit_handler("Ceiling color error", game);
}
