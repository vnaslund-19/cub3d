/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:00:32 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 18:02:26 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_explore(t_game *game, int ***visited)
{
	int	i;

	*visited = (int **)malloc((game->data->rows + 1) * sizeof(int *));
	if (!*visited)
		exit_handler("Malloc error", game);
	i = 0;
	while (i < (game->data->rows))
	{
		(*visited)[i++] = (int *)ft_calloc(game->data->max_cols, sizeof(int));
		if (!(*visited)[i - 1])
			exit_handler("Malloc error", game);
	}
	(*visited)[i] = NULL;
}

void	explore(t_game *game, int x, int y, int **visited)
{
	if (y == 0 && game->data->map[y][x] != '1')
		exit_handler("Player can get out of map", game);
	else if (visited[y][x] == 1 || game->data->map[y][x] == WALL)
		return ;
	else if (x < 0 || x >= (game->data->max_cols)
		|| y >= (game->data->rows - 1) || game->data->map[y][x] == ' '
		|| game->data->map[y][x] == '\n')
		exit_handler("Player can get out of map", game);
	visited[y][x] = 1;
	explore(game, x, (y - 1), visited);
	explore(game, x, (y + 1), visited);
	explore(game, (x + 1), y, visited);
	explore(game, (x - 1), y, visited);
}
