/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/12 17:40:28 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	revise_data(t_data *data)
{
	if (data->rfloor > 255 || data->rfloor < 0)
		exit_handler("Floor color error", data);
	else if (data->gfloor > 255 || data->gfloor < 0)
		exit_handler("Floor color error", data);
	else if (data->bfloor > 255 || data->bfloor < 0)
		exit_handler("Floor color error", data);
	else if (data->rceil > 255 || data->rceil < 0)
		exit_handler("Ceiling color error", data);
	else if (data->gceil > 255 || data->gceil < 0)
		exit_handler("Ceiling color error", data);
	else if (data->bceil > 255 || data->bceil < 0)
		exit_handler("Ceiling color error", data);
}

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
		return (printf("Exactly 1 map should be passed as argument"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit_handler("Malloc error", data);
	init_data(data);
	ft_read_file(data, argv);
	revise_data(data);

	int	i = 0;
	printf("\nMap:\n");
	while (data->map[i])
		printf("%s", data->map[i++]);
	printf("\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", data->no_path,
		data->so_path, data->we_path, data->ea_path);
	printf("rceil: %d, gceil: %d, bceil: %d\nrfloor: %d, gfloor: %d, bfloor: %d", data->rceil, data->gceil, data->bceil, data->rfloor, data->gfloor, data->bfloor);
	return (0);
}
