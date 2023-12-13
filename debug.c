/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:22:39 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/13 16:24:42 by vnaslund         ###   ########.fr       */
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
			printf("%d", visited[i][j]);
		printf("\n");
	}
}
