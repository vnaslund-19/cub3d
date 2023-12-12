/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:58:23 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/12 16:19:54 by vnaslund         ###   ########.fr       */
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

int	is_first_line_of_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '1'
				|| str[i] == '0' || str[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_file_check(t_data *data, char **file, int i) // Divide into smaller functions & protect mallocs (ft_split & ft_substr)
{
	char	**nums;

	if (!file[i])
		return ;
	else if (!ft_strncmp("\n", file[i], 2))
		ft_file_check(data, file, i + 1);
	else if (!ft_strncmp(file[i], "F ", 2))
	{
		nums = ft_split(file[i] + 2, ',');
		data->rfloor = ft_atoi(nums[0]);
		data->gfloor = ft_atoi(nums[1]);
		data->bfloor = ft_atoi(nums[2]);
		ft_free_array((void **)nums);
		ft_file_check(data, file, i + 1);
	}
	else if (!ft_strncmp(file[i], "C ", 2))
	{
		nums = ft_split(file[i] + 2, ',');
		data->rceil = ft_atoi(nums[0]);
		data->gceil = ft_atoi(nums[1]);
		data->bceil = ft_atoi(nums[2]);
		ft_free_array((void **)nums);
		ft_file_check(data, file, i + 1);
	}
	else if (!ft_strncmp(file[i], "NO ", 3))
	{
		data->no_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		ft_file_check(data, file, i + 1);
	}
	else if (!ft_strncmp(file[i], "SO ", 3))
	{
		data->so_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		ft_file_check(data, file, i + 1);
	}
	else if (!ft_strncmp(file[i], "WE ", 3))
	{
		data->we_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		ft_file_check(data, file, i + 1);
	}
	else if (!ft_strncmp(file[i], "EA ", 3))
	{
		data->ea_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		ft_file_check(data, file, i + 1);
	}
	else if (is_first_line_of_map(file[i]))
	{
		data->first_line_of_map = i;
		ft_fill_map(data);
	}
	else
		exit_handler("Found invalid line while parsing", data);
}
