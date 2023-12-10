/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:34:22 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/10 16:00:04 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_handler(char *msg, t_data *data)
{
	if (data->allocated_map)
		ft_free_matrix(data, (void **)data->map);
	free(data);
	printf("Error\n%s\n", msg);
	exit(1);
}

void	ft_free_matrix(t_data *data, void **matrix)
{
	int	i;

	i = 0;
	while (i < data->rows && matrix[i])
		free(matrix[i++]);
	free(matrix);
}

