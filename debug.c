/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:22:39 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/11 10:39:12 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_mapinfo(t_data *data)
{
	int	i = 0;

	printf("\nMap:\n");
	while (data->map[i])
		printf("%s", data->map[i++]);
	printf("\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", data->no_path,
		data->so_path, data->we_path, data->ea_path);
	printf("rceil: %d, gceil: %d, bceil: %d\nrfloor: %d, gfloor: %d, bfloor: %d", data->rceil, data->gceil, data->bceil, data->rfloor, data->gfloor, data->bfloor);
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
			printf("789%d", visited[i][j]);
		printf("\n");
	}
}
