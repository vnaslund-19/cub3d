/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:34:22 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/11 17:04:51 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_handler(char *msg, t_data *data)
{
	printf("Error\n%s\n", msg);
	//if (data->allocated_map)
	//	ft_free_array((void **)data->map);
	//if (data->allocated_file)
	//	ft_free_array((void **)data->file);
	free(data);
	exit(1);
}

void	ft_free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}
