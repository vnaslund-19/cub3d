/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:53:53 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/18 18:05:11 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycast(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->pixel_info = ray_caster(game, x);
/* 		printf("Ray Length: %f\n", *(game.pixel_info)->ray_len);
		printf("Ray Length (perdpendicular): %f\n", *(game.pixel_info)->distance); */
		// player is already initialized and its data is constatly updated
		// NEEDED: make calculations for:
		// ray length
		// What texture was hit
		// the x pos in which the texture was hit which is:
		// (floating-point part of x coordinate * texture_width)
		// and store data in some way inside t_game structure
		calc_wall_and_draw(game, x);
		free(game->pixel_info);
		game->pixel_info = NULL;
		x++;
	}
}
