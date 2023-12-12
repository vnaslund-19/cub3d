/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/12 16:02:09 by vnaslund         ###   ########.fr       */
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
		return (printf("Exactly 1 map should be passed as argument"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit_handler("Malloc error", data);
	init_data(data);
	ft_read_file(data, argv);

	int	i = 0;
	printf("\nMap:\n");
	while (data->map[i])
		printf("%s", data->map[i++]);
	printf("\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", data->no_path,
		data->so_path, data->we_path, data->ea_path);
	printf("rceil: %d, gceil: %d, bceil: %d\nrfloor: %d, gfloor: %d, bfloor: %d", data->rceil, data->gceil, data->bceil, data->rfloor, data->gfloor, data->bfloor);
	return (0);
}
