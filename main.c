/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:45:14 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/10 14:47:06 by vnaslund         ###   ########.fr       */
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
	ft_read_map(data, argv);
	return (0);
}