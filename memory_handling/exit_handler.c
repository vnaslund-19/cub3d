/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:34:22 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 17:50:26 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_handler(char *msg, t_game *game)
{
	printf("Error\n%s\n", msg);
	if (game->data->allocated_file)
		ft_free_array((void **)game->data->file);
	if (game->data->allocated_map)
		ft_free_array((void **)game->data->map);
	if (game->data->no_path)
		free(game->data->no_path);
	if (game->data->so_path)
		free(game->data->so_path);
	if (game->data->we_path)
		free(game->data->we_path);
	if (game->data->ea_path)
		free(game->data->ea_path);
	free(game->data);
	free(game);
	exit(1);
}

void	ft_free_array(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}
