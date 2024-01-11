/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/11 10:20:30 by gkrusta          ###   ########.fr       */
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
	t_data	*data;

	if (argc != 2)
	{
		printf("Exactly 1 map should be passed as argument");
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		exit_handler("Malloc error", data);
	init_data(data);
	ft_read_file(data, argv);
	debug_print_mapinfo(data);
	init_player(data);
	ft_end_game(data);
	return (0);
}
