/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:29 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/15 18:59:45 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_player player, double angle, int i)
{
	ray->ray_angle = get_ray_angle(player.view_angle, i);
	ray->d_angle = ray->ray_angle;
	ray->sign.x = 1;
	ray->sign.y = 1;
	if (cos(angle) < 0)
		ray->sign.x *= -1;
	if (sin(angle) > 0)
		ray->sign.y *= -1;
	ray->vertical.x = ray->sign.x;
	ray->vertical.y = tan(angle) * ray->sign.y;
	ray->horizontal.x = 1 / tan(angle) * ray->sign.x;
	ray->horizontal.y = ray->sign.y;
}

double	get_ray_angle(double angle, int i)
{
	double	ray_angle;

	ray_angle = M_PI / 2;
	return (ray_angle);
}

void	init_player(t_game *game, t_data *data)
{
	t_player	player;
	
	game->player = &player;
	player.x = (double)data->p_position[0] + 0.5;
	player.y =(double)data->p_position[1] + 0.5;
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
}

/* int	printer(t_data *data, t_player player)
{
	printf("Player position: (%.2f, %.2f)\n", data->pos.x, data->pos.y);
	printf("View angle: %.2f radians\n", data->pos.view_angle);
	return (0);
} */

void	determine_quadrant(t_player player, t_ray *ray)
{

	if (ray->sign.x > 0 && ray->sign.y < 0)
	{
		ray->d_angle = ray->ray_angle;
		ray->quadrant = 1;
	}
	else if (ray->sign.x < 0 && ray->sign.y < 0)
	{
		ray->d_angle = M_PI - ray->ray_angle;
		ray->quadrant = 2;
	}
	else if (ray->sign.x < 0 && ray->sign.y > 0)
	{
		ray->d_angle = ray->ray_angle - M_PI;
		ray->quadrant = 3;
	}
	else
	{
		ray->d_angle = 2 * M_PI - ray->ray_angle;
		ray->quadrant = 4;
	}
}

t_pos	get_first_step(t_player player, t_ray *ray, double angle, char crossing)
{
	t_pos	first_step;
	double	len;

	if (crossing = 'x')
	{
		if (ray->quadrant == 1 || ray->quadrant == 2)
			len = (player.y - floor(player.y)) / sin(angle);
		else
			len = (ceil(player.y) - player.y) / sin(angle);
	}
	else
	{
		if (ray->quadrant == 1 || ray->quadrant == 4)
			len = (ceil(player.x) - player.x) / cos(angle);
		else
			len = (player.x - floor(player.x)) / cos(angle);
	}
	first_step.x = player.x + player.x_raydir * len;
	first_step.y = player.y + player.y_raydir * len;
	return (first_step);
}

t_column	get_ray_length(t_ray *ray, t_game *game, t_pos step, char crossing)
{
	t_pos		first_step;
	t_column	pixel;
	t_player	player;
	double		delta;

	first_step = get_first_step(player, ray, ray->d_angle, crossing);
	player = game->player;
	delta = get_absoulte(ray->ray_angle, game->player->view_angle);
	while (1)
	{
		if (wall_check(game->data->map, ray, first_step, corssing))
		{
			pixel.wall_hit.x = first_step.x;
			pixel.wall_hit.y = first_step.y;
			break ;
		}
		first_step.x += step.x;
		first_step.y += step.y;
	}
	pixel.ray_len = sqrt(pow(player.x - pixel.wall_hit.x, 2)
		+ pow(player.y - pixel.wall_hit.y, 2));
	pixel.distance = pixel.ray_len * cos(delta);
	return (pixel);
}

void	ray_caster(t_game *game, t_data *data, int i)
{
	t_column	x_col;
	t_column	y_col;
	t_ray		ray;

	init_ray(&ray, player, i);
	x_col = get_ray_length(ray, game, ray.horizontal, 'x');
	y_col = get_ray_length(ray, game, ray.vertical 'y');
	if (x_col.ray_len > y_col.ray_len)
		return (y_col.ray_len);
	else
		return (x_col.ray_len);
}
