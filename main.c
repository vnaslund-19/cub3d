/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/18 15:53:09 by gkrusta          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game		*game;
	t_column	column;

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
	column = ray_caster(game);
	printf("Ray Length: %f\n", column.ray_len);
	printf("Ray Length (perdpendicular): %f\n", column.distance);
	//printf("texture: %c\n", column.texture);
	init_window(game);
	ft_end_game(game);
	return (0);
}
