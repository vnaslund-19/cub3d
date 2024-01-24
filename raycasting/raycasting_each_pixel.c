/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_each_pixel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:56:50 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/24 16:31:00 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_pos	get_first_step(t_player *player, t_ray *ray, double angle,
						char crossing)
{
	t_pos	first_step;
	double	len;

	if (crossing == 'x')
	{
		if (ray->quadrant == 1 || ray->quadrant == 2)
			len = fabs((player->y - floor(player->y)) / sin(angle));
		else
			len = fabs((ceil(player->y) - player->y) / sin(angle));
	}
	else
	{
		if (ray->quadrant == 1 || ray->quadrant == 4)
			len = fabs((ceil(player->x) - player->x) / cos(angle));
		else
			len = fabs((player->x - floor(player->x)) / cos(angle));
	}
	first_step.x = player->x + len * cos(angle) * ray->sign.x;
	first_step.y = player->y + len * sin(angle) * ray->sign.y;
	return (first_step);
}

t_pos	get_ray_pos(t_ray *ray, t_game *game, t_pos step, char crossing)
{
	t_pos		ray_pos;

	ray_pos = get_first_step(game->player, ray, ray->d_angle, crossing);
	while (1)
	{
		if (wall_check(game->data, ray, ray_pos, crossing) == true)
			break ;
		ray_pos.x += step.x;
		ray_pos.y += step.y;
	}
	return (ray_pos);
}

t_column	*init_pixel_column(t_ray *ray, t_game *game, t_pos step,
								char crossing)
{
	t_pos		ray_pos;
	t_column	*pixel;
	double		delta;

	delta = 0;
	pixel = malloc(sizeof(t_column));
	ray_pos = get_ray_pos(ray, game, step, crossing);
	pixel->ray_len = INT_MAX;
	pixel->distance = INT_MAX;
	if (IS_IN_RANGE(ray_pos.x) && IS_IN_RANGE(ray_pos.y))
	{
		pixel->ray_len = sqrt(pow(game->player->x - ray_pos.x, 2)
				+ pow(game->player->y - ray_pos.y, 2));
		delta = get_absoulte(ray->ray_angle, game->player->view_angle);
		pixel->distance = pixel->ray_len * cos(delta);
		pixel->texture = get_rays_texture(game, &ray_pos, ray);
		pixel->wall_hit = get_fractional_part(&ray_pos);
	}
	return (pixel);
}

t_column	*ray_caster(t_game *game, int x)
{
	t_column	*x_col;
	t_column	*y_col;
	t_ray		ray;

	x_col = NULL;
	y_col = NULL;
	init_ray(&ray, game->player, x);
	x_col = init_pixel_column(&ray, game, ray.horizontal, 'x');
	y_col = init_pixel_column(&ray, game, ray.vertical, 'y');
	if (x_col->distance > y_col->distance)
	{
		free(x_col);
		return (y_col);
	}
	else
	{
		free(y_col);
		return (x_col);
	}
}
