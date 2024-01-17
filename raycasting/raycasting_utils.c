/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:55 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/17 16:15:58 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_absoulte(double ray_angle, double view_angle)
{
	return (fabs(ray_angle - view_angle));
}

void	align_coordinates(t_ray *ray, int *i, int *j, char crossing)
{
	if (crossing == 'y' && ray->sign.x == -1)
		--(*i);
	else if (crossing == 'x' && ray->sign.y == -1)
		--(*j);
	else
		return ;
}

bool	wall_check(t_data *data, t_ray *ray, t_pos step, char crossing)
{
	int		i;
	int		j;
	char	**map;

	i = (int)step.x;
	j = (int)step.y;
	map = data->map;
	align_coordinates(ray, &i, &j, crossing);
	if (abs(j + 1) > data->rows && crossing == 'y')
		return (true);
	if (abs(i + 1) > data->max_cols && crossing == 'x')
		return (true);
	printf("from crossing %c:\n i: %d and j: %d\n", crossing, i, j);
	if (map[j][i] == '1')
		return (true);
	return (false);
}
