/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:38 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/11 18:46:22 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_spaces(t_data *data, char **map, int max_cols)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		temp = malloc(len + 1);
		if (!temp)
			exit_handler("malloc error", data);
		ft_strlcpy(temp, map[i], len + 1);
		free(map[i]);
		map[i] = malloc(max_cols + 1);
		if (!map[i])
			exit_handler("malloc error", data);
		ft_strlcpy(map[i], temp, max_cols + 1);
		while (len < max_cols)
			map[i][len++] = ' ';
		map[i][len] = '\0';
		i++;
		free(temp);
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
		data->map[j++] = data->file[i++];
	data->map[j] = NULL;
	data->rows = data->lines - i;
	max_len = 0;
	i = -1;
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) > max_len)
			max_len = ft_strlen(data->map[i]);
	}
	data->max_cols = max_len;
	//add_spaces(data, data->map, data->max_cols);
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

void	ft_file_check(t_data *data, char **file, int i)
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

void	ft_playable_check(t_data *data, char **map)
{
	//int	**visited;

	data->players = 0;
	player_config_check(data, map);
	if (data->players != 1)
		exit_handler("Map error: exactly 1 player position needed", data);
	//init_explore(data, &visited);
	//explore(data, data->p_position[0], data->p_position[1], visited);
	//debug_print_visited(visited, data->rows, data->max_cols);

	//ft_free_array((void **)visited);
}

void	player_config_check(t_data *data, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->players++;
				data->p_position[0] = j;
				data->p_position[1] = i;
				data->direction = map[i][j];
			}
			else if (map[i][j] != EMPTY && map[i][j] != ' ' &&
				map[i][j] != WALL && map[i][j] != '\n')
				exit_handler("Map error: Invalid character found", data);
		}
	}
}
