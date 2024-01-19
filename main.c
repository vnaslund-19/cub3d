/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/19 16:52:11 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_game *game)
{
	game->data->no_path = NULL;
	game->data->so_path = NULL;
	game->data->we_path = NULL;
	game->data->ea_path = NULL;
	game->textures = NULL;
	game->player = NULL;
}

int	main(int argc, char **argv)
{
	t_game	*game;

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
	init_data(game);
	ft_read_file(game, argv);
	init_player(game);
	init_window(game);
	ft_end_game(game);
	return (0);
}
