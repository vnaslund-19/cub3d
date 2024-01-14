/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:29 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/14 22:09:43 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//t_player player, t_data *data



double	get_ray_angle(int i)
{
/* 	double	side_h;
	double	side_a;
	double	side_b
	double	angle_a;

	side_h = (WIDTH / 2) / sin(M_PI / 4);
	side_a = 0.5 + i;
	while (d < WIDTH / 2)
	{
		side_a = sqrt(side_a * side_a + side_h * side_h)
			- 2 * side_a + side_h * code(M_PI / 4);
		d += 1;
		player.ray_angle = player.view_angle + angle_a;
	}
	if (data->player_direction == 'N')
	{
		player.ray_angle = // ray angle is players view angle / FOV
	}

	x_ststep = cos();
	y_ststep = sin(); */
	//The ray starts at the position of the player (posX, posY)
/* 	if ()
		hit = true;
	else
		 */
	double	ray_angle;

	ray_angle = M_PI / 2;
	return (ray_angle);
}

void	init_player(t_data *data)
{

	data->rows = 5;
	data->max_cols = 6;
	player.x = (double)data->p_position[0] + 0.5;
	player.y =(double)data->p_position[1] + 0.5;
/* 	data->mapx = (int)player.x;
	data->mapy = (int)player.y; */
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
}

int	printer(t_data *data, t_player player)
{
	printf("Player position: (%.2f, %.2f)\n", data->pos.x, data->pos.y);
	printf("View angle: %.2f radians\n", data->pos.view_angle);
	return (0);
}

int	determine_quadrant(t_player player)
{
	int	quadrant;
	
	if (player->x_raydir > 0 && player->y_raydir < 0)
		quadrant = 1;
	else if (player->x_raydir < 0 && player->y_raydir < 0)
		quadrant = 2;
	else if (player->x_raydir < 0 && rplayer->y_raydir > 0)
		quadrant = 3;
	else
		quadrant = 4;
	return (quadrant);
}

t_ray_steps	get_first_step(t_data *data, t_player player, double angle, char crossing)
{
	t_ray_steps	first_step;
	double		len;

	if (crossing = 'x')
	{
		if (determine_quadrant(player) == 1)
			len = (player.y - floor(player.y)) / sin(angle);
		else if (determine_quadrant(player) == 2)
			len = (player.y - floor(player.y)) / sin(M_PI - angle);
		else if (determine_quadrant(player) == 3)
			len = (ceil(player.y) - player.y) / sin(angle - M_PI);
		else
			len = (ceil(player.y) - player.y) / sin(angle - 2 * M_PI - angle);
		first_step.x = player.x + len * cos(angle);
		first_step.y = player.y - len * sin(angle);
	}
	else
	{
		if (determine_quadrant(player) == 1)
			len = (player.y - floor(player.y)) / sin(angle);
	}
	return (first_step);
}

/* bool	wall_check()
{
	if (map[j][i] == '1')
		return (true);
	return (false);
} */

t_column	get_ray_length(t_data *data, t_player player, char crossing)
{
	t_ray_steps	first_step;
	t_column	ray;

	first_step = get_first_step(player, player->ray_angle, crossing);
	while (1)
	{
		if (wall_check())
		{
			ray.wall_hit.x = first_step.x;
			ray.wall_hit.x = first_step.y;
			break ;
		}
		
		first_step.x += 
		first_step.y += 
	}
}

void	ray_caster(t_data *data)
{
	t_player	player;
	t_column	x_col;
	t_column	y_col;

	player = data->pos;
	init_player(data, player);
	x_col = get_ray_length(data, player, 'x');
	y_col = get_ray_length(data, player, 'y');
	if (x_col->ray_len > y_col->ray_len)
		return (y_col->ray_len);
	else
		return (x_col->ray_len);
}