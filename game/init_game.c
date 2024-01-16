/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:05:23 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/16 12:39:59 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_window(t_game *game)
{
	load_textures(game);
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", true);
	if (!game->mlx)
		exit_handler("mlx_init error", game);
	mlx_set_window_limit(game->mlx, MIN_WIDTH, MIN_HEIGHT,
		WIN_WIDTH, WIN_HEIGHT);
	game->image = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	draw_floor_and_ceiling(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	load_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		exit_handler("Malloc error", game);
	/*game->textures->north = mlx_load_png(game->data->no_path);
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
		exit_handler("EA texture", game);*/
	game->textures->floor_color = get_rgba(game->data->rfloor,
			game->data->gfloor, game->data->bfloor, 255);
	game->textures->ceiling_color = get_rgba(game->data->rceil,
			game->data->gceil, game->data->bceil, 255);
}

void	set_start_angles(t_game *game)
{
	if (game->data->player_direction == 'N')
	{
		game->player->view_angle = M_PI / 2;
		game->player->x_viewdir = 0;
		game->player->y_viewdir = -1;
	}
	else if (game->data->player_direction == 'S')
	{
		game->player->view_angle = M_PI * 3 / 2;
		game->player->x_viewdir = 0;
		game->player->y_viewdir = 1;
	}
	else if (game->data->player_direction == 'E')
	{
		game->player->view_angle = 0;
		game->player->x_viewdir = 1;
		game->player->y_viewdir = 0;
	}
	else
	{
		game->player->view_angle = M_PI;
		game->player->x_viewdir = -1;
		game->player->y_viewdir = 0;
	}
}

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		exit_handler("Malloc error", game);
	game->player->x = (double)game->data->p_position[0] + 0.5;
	game->player->y = (double)game->data->p_position[1] + 0.5;
	set_start_angles(game);
	game->player->ray_angle = game->player->view_angle;
	game->player->x_raydir = game->player->x_viewdir;
	game->player->y_raydir = game->player->y_viewdir;
}
