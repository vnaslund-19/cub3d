/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:29 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/11 11:58:35 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	get_first_pos(t_player player, t_data *data)
{
	double	s;
	double	d;
	double	x_ststep;
	double	y_ststep;
	double delta;

	s = WIDTH / 2;
	d = 0.5;
	while (d < WIDTH / 2)
	{
		delta = asin(d/sqrt(d * d + s * s));
		d += 1;
		player.ray_angle = player.view_angle + delta;
	}
	if (data->player_direction == 'N')
	{
		player.ray_angle = // ray angle is players view angle / FOV
	}

	x_ststep = cos();
	y_ststep = sin();
	//The ray starts at the position of the player (posX, posY)
/* 	if ()
		hit = true;
	else
		 */
}

void	init_player(t_data *data)
{
	t_player	player;

	player = data->pos;
	data->rows = 5;
	data->max_cols = 6;
	player.x = (double)data->p_position[0] + 0.5;
	player.y =(double)data->p_position[1] + 0.5;
/* 	data->mapx = (int)player.x;
	data->mapy = (int)player.y; */
	//data->player_direction = data->map[data->mapx][data->mapy];
	data->hit = false;
	if (data->player_direction == 'N')
	{
		player.view_angle = M_PI / 2;
		player.x_viewdir = 0;
		player.y_viewdir = -1;
	}
	else if (data->player_direction == 'S')
	{
		player.view_angle = M_PI * 3 / 2;
		player.x_viewdir = 0;
		player.y_viewdir = 1;
	}
	else if (data->player_direction == 'E')
	{
		player.view_angle = 0;
		player.x_viewdir = 1;
		player.y_viewdir = 0;
	}
	else
	{
		player.view_angle = M_PI;
		player.x_viewdir = -1;
		player.y_viewdir = 0;
	}
	player.ray_angle = player.view_angle;
	player.x_raydir = player.x_viewdir;
	player.y_raydir = player.y_viewdir;
	get_first_pos(player, data);
}

int	printer(t_data *data, t_player player)
{
	printf("Player position: (%.2f, %.2f)\n", data->pos.x, data->pos.y);
	printf("View angle: %.2f radians\n", data->pos.view_angle);
	return (0);
}
