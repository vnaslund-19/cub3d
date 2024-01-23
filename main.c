/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/23 19:49:44 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_game *game)
{
	game->data->no_path = NULL;
	game->data->so_path = NULL;
	game->data->we_path = NULL;
	game->data->ea_path = NULL;
	game->data->rceil = -1;
	game->data->gceil = -1;
	game->data->bceil = -1;
	game->data->rfloor = -1;
	game->data->gfloor = -1;
	game->data->bfloor = -1;
	game->textures = NULL;
	game->player = NULL;
}

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

bool	file_valid(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len > 4 && !ft_strncmp(name + len - 4, ".cub", 4))
		return (true);
	else
	{
		printf("The file should have a '.cub' extension.\n");
		return (false);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	atexit(ft_leaks);
	if (argc != 2)
	{
		printf("Exactly 1 map should be passed as argument");
		return (1);
	}
	if (!file_valid(argv[1]))
		return (1);
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
