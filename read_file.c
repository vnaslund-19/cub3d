/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:58:23 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/12 16:47:18 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_file(t_data *data, char **argv)
{
	int		fd;
	int		i;
	int		line_count;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_handler("Map error: open error", data);
	line_count = ft_allocate_lines(data, argv);
	data->allocated_file = true;
	i = 0;
	while (line_count--)
	{
		data->file[i] = get_next_line(fd);
		if (data->file[i] == NULL)
			exit_handler("Map error: gnl error", data);
		i++;
	}
	data->file[i] = NULL;
	get_next_line(-1);
	data->map = NULL;
	ft_file_check(data, data->file, 0);
	if (!data->map)
		exit_handler("map not found", data);
	ft_playable_check(data, data->map);
}

int	ft_allocate_lines(t_data *data, char **argv)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_handler("Map error: open error", data);
	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
		line_count++;
	}
	close(fd);
	data->lines = line_count;
	data->file = (char **)malloc((line_count + 1) * sizeof(char *));
	if (!data->map)
		exit_handler("Malloc error", data);
	return (line_count);
}
