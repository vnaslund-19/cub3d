/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:05:23 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 16:34:27 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_window(t_data *data)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "CUB3D", true);
	if (!mlx)
		exit_handler("mlx_init error", data);
	mlx_set_window_limit(mlx, MIN_WIDTH, MIN_HEIGHT, WIN_WIDTH, WIN_HEIGHT);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
