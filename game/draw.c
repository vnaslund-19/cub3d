/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:12:39 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/15 13:06:43 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor_and_ceiling(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			mlx_put_pixel(game->image, x, y, game->textures->ceiling_color);
			y++;
		}
		while (y < WIN_HEIGHT)
		{
			mlx_put_pixel(game->image, x, y, game->textures->floor_color);
			y++;
		}
		x++;
	}
}

void	draw_texture(t_game	*game, mlx_texture_t *texture)
{
	u_int32_t	y;
	u_int32_t	x;

	x = 0;
	while (x < texture->width * 12)
	{
		y = 0;
		while (y < texture->height * 12)
		{
			mlx_put_pixel(game->image, x, y,
				get_texture_pixel_color(texture, y % 64, x % 64));
			y++;
		}
		x++;
	}
}
