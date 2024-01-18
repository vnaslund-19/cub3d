/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:37:51 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/18 13:39:27 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_extension(t_player *player, t_data *data)
{
	if (data->player_direction == 'E')
	{
		player->view_angle = 0;
		player->x_viewdir = 1;
		player->y_viewdir = 0;
	}
	else
	{
		player->view_angle = M_PI;
		player->x_viewdir = -1;
		player->y_viewdir = 0;
	}
}

void	init_player(t_player *player, t_data *data)
{

	player->x = (double)data->p_position[0] + 0.5;
	player->y =(double)data->p_position[1] + 0.5;
	if (data->player_direction == 'N')
	{
		player->view_angle = M_PI / 2;
		player->x_viewdir = 0;
		player->y_viewdir = -1;
	}
	else if (data->player_direction == 'S')
	{
		player->view_angle = M_PI * 3 / 2;
		player->x_viewdir = 0;
		player->y_viewdir = 1;
	}
	else
		init_player_extension(player, data);
}