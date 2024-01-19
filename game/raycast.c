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
		calc_wall_and_draw(game, x);
		free(game->pixel_info);
		game->pixel_info = NULL;
		x++;
	}
}
