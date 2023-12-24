/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:01:03 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/19 14:10:20 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	new = malloc(size);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}

void	add_spaces(t_data *data, char **map, int max_cols)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		if (len < max_cols)
		{
			map[i] = realloc(map[i], max_cols + 2);
			if (!map[i])
				exit_handler("realloc error", data);
			while (len < max_cols)
				map[i][len++] = ' ';
			map[i][max_cols] = '\n';
			map[i][max_cols + 1] = '\0';
		}
		i++;
	}
}

void	ft_fill_map(t_data *data)
{
	int		i;
	int		j;
	size_t	max_len;

	i = data->first_line_of_map;
	data->map = malloc(sizeof(char *) * (data->lines - i + 1));
	if (!data->map)
		exit_handler("Malloc error", data);
	data->allocated_map = true;
	j = 0;
	while (data->file[i])
		data->map[j++] = ft_strdup(data->file[i++]);
	data->map[j] = NULL;
	data->rows = j;
	max_len = 0;
	i = -1;
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) > max_len)
			max_len = ft_strlen(data->map[i]);
	}
	data->max_cols = max_len - 1;
	add_spaces(data, data->map, data->max_cols);
}
