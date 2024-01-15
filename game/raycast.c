/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:53:53 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/15 16:03:19 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycast(t_game *game)
{
	int	x;

	x = 0;
	while (x <= WIN_WIDTH)
	{
		// player is already initialized and its data is constatly updated
		// NEEDED: make calculations for:
		// ray length
		// What texture was hit
		// the x pos in which the texture was hit which is:
		// (floating-point part of x coordinate * texture_width)
		// and store data in some way inside t_game structure
		calc_wall_and_draw(game, x);
		x++;
	}
}
