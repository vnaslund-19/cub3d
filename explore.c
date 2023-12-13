/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:00:32 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/13 18:00:09 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_explore(t_data *data, int ***visited)
{
	int	i;

	*visited = (int **)malloc((data->rows + 1) * sizeof(int *));
	if (!*visited)
		exit_handler("Malloc error", data);
	i = 0;
	while (i < (data->rows))
	{
		(*visited)[i++] = (int *)ft_calloc(data->max_cols, sizeof(int));
		if (!(*visited)[i - 1])
			exit_handler("Malloc error", data);
	}
}

void	explore(t_data *data, int x, int y, int **visited)
{
	if (y == 0 && data->map[y][x] != '1')
		exit_handler("Player can get out of map", data);
	else if (visited[y][x] == 1 || data->map[y][x] == WALL)
		return ;
	else if (x < 0 || x >= (data->max_cols)
		|| y >= (data->rows - 1) || data->map[y][x] == ' '
		|| data->map[y][x] == '\n')
		exit_handler("Player can get out of map", data);
	visited[y][x] = 1;
	explore(data, x, (y - 1), visited);
	explore(data, x, (y + 1), visited);
	explore(data, (x + 1), y, visited);
	explore(data, (x - 1), y, visited);
}
