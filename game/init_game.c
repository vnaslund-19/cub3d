/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:05:23 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 16:13:41 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_window(t_data *data)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1920, 1080, "CUB3D", true);
	if (!mlx)
		exit_handler("mlx_init error", data);
	img = mlx_new_image(mlx, 700, 700);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
