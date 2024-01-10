/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 18:10:08 by vnaslund         ###   ########.fr       */
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
	init_data(game->data);
	ft_read_file(game, argv);
	//debug_print_mapinfo(data);
	init_window(game);
	ft_end_game(game);
	return (0);
}
