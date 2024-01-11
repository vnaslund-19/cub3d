/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:05:23 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 18:23:12 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_window(t_game *game)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", true);
	if (!mlx)
		exit_handler("mlx_init error", game);
	mlx_set_window_limit(mlx, MIN_WIDTH, MIN_HEIGHT, WIN_WIDTH, WIN_HEIGHT);
	//load_textures(game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

void	load_textures(t_game *game)
{
	game->textures->north = mlx_load_png(game->data->no_path);
	if (!game->textures->north)
		exit_handler("NO texture", game);
	game->textures->south = mlx_load_png(game->data->so_path);
	if (!game->textures->south)
		exit_handler("SO texture", game);
	game->textures->west = mlx_load_png(game->data->we_path);
	if (!game->textures->west)
		exit_handler("WE texture", game);
	game->textures->east = mlx_load_png(game->data->ea_path);
	if (!game->textures->east)
		exit_handler("EA texture", game);
}