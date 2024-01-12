/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:11:49 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/12 15:09:09 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate(t_game *game, int angle)
{
	double	new_angle;

	new_angle = game->player->view_angle + (ROTATION_SPEED * angle);
	if (new_angle > 2 * M_PI)
		new_angle -= 2 * M_PI;
	else if (new_angle < 0)
		new_angle += 2 * M_PI;
	game->player->view_angle = new_angle;
	game->player->x_viewdir = cos(game->player->view_angle);
	game->player->y_viewdir = sin(game->player->view_angle);
	printf("rotation detected\n");
}
