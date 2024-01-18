/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:45:33 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/11 15:51:45 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
