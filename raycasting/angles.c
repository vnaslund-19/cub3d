/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:29 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/24 16:21:27 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->ray_angle = get_ray_angle(player->view_angle, x);
	ray->sign.x = 1;
	ray->sign.y = 1;
	if (cos(ray->ray_angle) < 0)
		ray->sign.x *= -1;
	if (sin(ray->ray_angle) > 0)
		ray->sign.y *= -1;
	determine_quadrant(ray);
	ray->vertical.x = ray->sign.x;
	ray->vertical.y = -(tan(ray->ray_angle) * ray->vertical.x);
	ray->horizontal.y = ray->sign.y;
	ray->horizontal.x = -(ray->horizontal.y / tan(ray->ray_angle));
}

double	get_ray_angle(double angle, double x)
{
	double	ray_angle;
	double	delta;

	delta = (WIN_WIDTH / 2 - x);
	ray_angle = delta / (sqrt(pow(delta, 2) + pow(WIN_WIDTH / 2, 2)));
	if (x < WIN_WIDTH / 2)
	{
		delta = (WIN_WIDTH / 2 - x);
		ray_angle = asin(delta / (sqrt(pow(delta, 2) + pow(WIN_WIDTH / 2, 2))));
		return (angle + ray_angle);
	}
	else
	{
		delta = (x - WIN_WIDTH / 2);
		ray_angle = asin(delta / (sqrt(pow(delta, 2) + pow(WIN_WIDTH / 2, 2))));
		return (angle - ray_angle);
	}
}

void	determine_quadrant(t_ray *ray)
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
