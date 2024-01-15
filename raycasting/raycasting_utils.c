/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:55 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/15 18:54:45 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_absoulte(double ray_angle, double view_angle)
{
	return (fabs(ray_angle - view_angle));
}

bool	wall_check(char **map, t_ray *ray, t_pos first_step, char corssing)
{
	int		i;
	int		j;

	i = (int)first_step.x;
	j = (int)firs_step.y;
	if (crossing == 'y' && ray->sign.x == -1)
		i--;
	if (crossing == 'x' && ray->sign.y == -1)
		j--;
	if (map[i][j] == '1')
		return (true);
	return (false);
}
