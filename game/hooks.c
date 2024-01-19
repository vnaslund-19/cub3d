/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:55:06 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/19 13:39:32 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

void	loop_hook(void	*param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		raycast(game);
		move_forward(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		raycast(game);
		move_backward(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		raycast(game);
		move_left(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		raycast(game);
		move_right(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		raycast(game);
		rotate(game, 1);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		raycast(game);
		rotate(game, -1);
	}
}
