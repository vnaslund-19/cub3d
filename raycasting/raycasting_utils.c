/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:55 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/16 11:15:19 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_absoulte(double ray_angle, double view_angle)
{
	return (fabs(ray_angle - view_angle));
}

bool	wall_check(t_data *data, t_ray *ray, t_pos step, char crossing)
{
	int		i;
	int		j;

	i = (int)step.x;
	j = (int)step.y;
	if (crossing == 'y' && ray->sign.x == -1)
		i--;
	if (crossing == 'x' && ray->sign.y == -1)
		j--;
	if ((j == 0 || j == data->rows) && crossing == 'y')
		return (true);
	if ((i == 0 || i == data->max_cols) && crossing == 'x')
		return (true);
	if (data->map[i][j] == '1')
		return (true);
	return (false);
}
