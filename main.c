/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/11 17:26:38 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (printf("Exactly 1 map should be passed as argument"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit_handler("Malloc error", data);
	ft_read_file(data, argv);

	int	i = 0;
	while (data->map[i])
		printf("%s", data->map[i++]);
	printf("\n\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", data->no_path,
		data->so_path, data->we_path, data->ea_path);
	printf("rceil: %d, gceil: %d, bceil: %d\nrfloor: %d, gfloor: %d, bfloor: %d", data->rceil, data->gceil, data->bceil, data->rfloor, data->gfloor, data->bfloor);
	return (0);
}
