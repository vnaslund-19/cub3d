/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/18 17:05:31 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
}

void	printer(t_game *game)
{
	t_player *player = game->player;

	printf("Player position: (%.2f, %.2f)\n", player->x, player->y);
	printf("View angle: %.2f radians\n", player->view_angle);
}

void	raycast(t_game *game, t_column *pixel_info)
{
	int	x;

	x = 0;
	while (x <= WIN_WIDTH)
	{
		*pixel_info = ray_caster(game, x);
		printf("Ray Length: %f\n", pixel_info->ray_len);
		printf("Ray Length (perdpendicular): %f\n", pixel_info->distance);
		//calc_wall_and_draw(game, x);
		x = x + 1;
	}
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
	{
		printf("Exactly 1 map should be passed as argument");
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		exit_handler("Malloc error", game);
	game->data = malloc(sizeof(t_data));
	if (!game->data)
		exit_handler("Malloc error", game);
	init_data(game->data);
	ft_read_file(game, argv);
	debug_print_mapinfo(game->data);
	game->player = malloc(sizeof(t_player));
	init_player(game->player, game->data);
	init_window(game);
	printer(game);
	game->pixel_info = malloc(sizeof(t_column));
	raycast(game, game->pixel_info);
	ft_end_game(game);
	return (0);
}
