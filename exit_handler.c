/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:34:22 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/19 17:24:41 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_end_game(t_game *game)
{
	ft_free_array((void **)game->data->map);
	free(game->data->no_path);
	free(game->data->so_path);
	free(game->data->we_path);
	free(game->data->ea_path);
	free(game->data);
	mlx_delete_texture(game->textures->north);
	mlx_delete_texture(game->textures->south);
	mlx_delete_texture(game->textures->west);
	mlx_delete_texture(game->textures->east);
	free(game->textures);
	free(game->player);
	free(game);
}

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
	if (game->textures)
		free_textures(game->textures);
	if (game->player)
		free(game->player);
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

void	free_textures(t_textures *textures)
{
	if (textures->north)
		mlx_delete_texture(textures->north);
	if (textures->south)
		mlx_delete_texture(textures->south);
	if (textures->west)
		mlx_delete_texture(textures->west);
	if (textures->east)
		mlx_delete_texture(textures->east);
	free(textures);
}
