/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:00:32 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/11 18:09:59 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_explore(t_data *data, int ***visited)
{
	int	i;

	*visited = (int **)malloc(data->rows * sizeof(int *));
	if (!*visited)
		exit_handler("Malloc error", data);
	i = 0;
	while (i < data->rows)
	{
		(*visited)[i++] = (int *)ft_calloc(data->max_cols, sizeof(int));
		if (!(*visited)[i - 1])
			exit_handler("Malloc error", data);
	}
}

void	explore(t_data *data, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || x >= (data->max_cols + 1) || y >= (data->rows + 1)
		|| visited[y][x] == 1 || data->map[y][x] == WALL)
		return ;
	else if (data->map[y][x] == ' ')
		exit_handler("Player can get out of map", data);
	visited[y][x] = 1;
	explore(data, x, (y - 1), visited);
	explore(data, x, (y + 1), visited);
	explore(data, (x + 1), y, visited);
	explore(data, (x - 1), y, visited);
}

void	debug_print_visited(int **visited, int rows, int cols)
{
	if (!visited)
	{
		printf("Visited array is NULL.\n");
		return ;
	}
	printf("Visited Array:\n");
	for (int i = 0; i < rows; i++)
	{
    	for (int j = 0; j < cols; j++)
			printf("%d ", visited[i][j]);
		printf("\n");
	}
}
