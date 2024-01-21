/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:12:39 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/21 16:00:43 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	calc_y_pixel(int w_start, int w_end, int y, int texture_height)
{
	double	relative_y;
	int		texture_y;

	relative_y = (double)(y - w_start) / (w_end - w_start);
	texture_y = (int)(relative_y * texture_height);
	if (texture_y > texture_height - 1)
		texture_y = texture_height - 1;
	else if (texture_y < 0)
		texture_y = 0;
	return (texture_y);
}

void	draw_column(t_game *game, int x, int w_start, int w_end)
{
	int	y;

	y = 1;
	while (y < WIN_HEIGHT)
	{
		if (y < w_start)
			mlx_put_pixel(game->image, x, y, game->textures->ceiling_color);
		else if (y > w_end)
			mlx_put_pixel(game->image, x, y, game->textures->floor_color);
		else
			mlx_put_pixel(game->image, x, y,
				get_texture_pixel_color(game->pixel_info->texture,
					calc_y_pixel(w_start, w_end, y, game->pixel_info->texture->height),
					game->pixel_info->wall_hit
					* game->pixel_info->texture->width));
		y++;
	}
}

void	calc_wall_and_draw(t_game *game, int x)
{
	int	w_height;
	int	w_start;
	int	w_end;

	w_height = WIN_HEIGHT / game->pixel_info->distance;
	w_start = (WIN_HEIGHT / 2) - (w_height / 2);
	if (w_start < 0)
		w_start = 0;
	w_end = (WIN_HEIGHT / 2) + (w_height / 2);
	if (w_end > WIN_HEIGHT)
		w_end = WIN_HEIGHT;
	draw_column(game, x, w_start, w_end);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// texture->pixels is a pointer to the start of the pixel data of the texture.
// It is a linear buffer that contains rgba values in order for every pixel
int	get_texture_pixel_color(mlx_texture_t *texture, int y, int x)
{
	uint8_t	*pixel;

	pixel = texture->pixels + (((y * texture->width) + x)
			* texture->bytes_per_pixel);
	return (get_rgba(pixel[0], pixel[1], pixel[2], pixel[3]));
}
