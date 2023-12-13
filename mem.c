/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:34:22 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/13 17:02:24 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_handler(char *msg, t_data *data)
{
	int	i;

	printf("Error\n%s\n", msg);
	i = 0;
	if (data->allocated_map)
	{
		while (i < data->first_line_of_map)
			free(data->file[i++]);
		free(data->file);
		ft_free_array((void **)data->map);
	}
	else if (data->allocated_file)
		ft_free_array((void **)data->file);
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
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
