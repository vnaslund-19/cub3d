/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:30:59 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/16 12:36:09 by vnaslund         ###   ########.fr       */
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
	/*mlx_delete_texture(game->textures->north);
	mlx_delete_texture(game->textures->south);
	mlx_delete_texture(game->textures->west);
	mlx_delete_texture(game->textures->east);*/
	free(game->textures);
	free(game->player);
	free(game);
}
