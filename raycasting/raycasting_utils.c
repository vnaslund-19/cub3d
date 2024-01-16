/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:55 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/16 15:49:52 by gkrusta          ###   ########.fr       */
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
	char	**map;

	i = (int)step.x;
	j = (int)step.y;
	map = data->map;
	if (crossing == 'y' && ray->sign.x == -1)
		i--;
	if (crossing == 'x' && ray->sign.y == -1)
		j--;
	if (abs(j + 1) > data->rows && crossing == 'y')
		return (true);
	if (abs(i + 1) > data->max_cols && crossing == 'x')
		return (true);
	printf(" from crossing %c i is %d \n j is %d\n", crossing, i, j);
	printf(" abs i is %d and abs j is %d\n", abs(i), abs(j));
	printf("rows is %d  colums is %d \n", data->rows, data->max_cols);
	if (map[i][j] == '1')
		return (true);
	return (false);
}
