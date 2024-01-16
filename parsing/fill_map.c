/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:01:03 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/16 12:34:41 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_realloc(void *ptr, size_t new_size, size_t og_size)
{
	void	*new;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new = malloc(new_size);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, og_size);
	free(ptr);
	return (new);
}

void	add_spaces(t_game *game, char **map, int max_cols)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		if (len < max_cols)
		{
			map[i] = ft_realloc(map[i], max_cols + 2, len);
			if (!map[i])
				exit_handler("realloc error", game);
			while (len < max_cols)
				map[i][len++] = ' ';
			map[i][max_cols] = '\n';
			map[i][max_cols + 1] = '\0';
		}
		i++;
	}
}

void	ft_fill_map(t_game *game)
{
	int		i;
	int		j;
	size_t	max_len;

	i = game->data->first_line_of_map;
	game->data->map = malloc(sizeof(char *) * (game->data->lines - i + 1));
	if (!game->data->map)
		exit_handler("Malloc error", game);
	game->data->allocated_map = true;
	j = 0;
	while (game->data->file[i])
		game->data->map[j++] = ft_strdup(game->data->file[i++]);
	ft_free_array((void **)game->data->file);
	game->data->allocated_file = false;
	game->data->map[j] = NULL;
	game->data->rows = j;
	max_len = 0;
	i = -1;
	while (game->data->map[++i])
	{
		if (ft_strlen(game->data->map[i]) > max_len)
			max_len = ft_strlen(game->data->map[i]);
	}
	game->data->max_cols = max_len - 1;
	add_spaces(game, game->data->map, game->data->max_cols);
}
