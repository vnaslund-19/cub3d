/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:25:31 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/19 14:10:21 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_file_check(t_data *data, char **file, int i)
{
	if (!file[i])
		return ;
	else if (!ft_strncmp("\n", file[i], 2))
		ft_file_check(data, file, i + 1);
	else if (find_floor_or_ceil(data, file, i))
		ft_file_check(data, file, i + 1);
	else if (find_no_or_so(data, file, i))
		ft_file_check(data, file, i + 1);
	else if (find_we_or_ea(data, file, i))
		ft_file_check(data, file, i + 1);
	else if (is_first_line_of_map(file[i]))
	{
		data->first_line_of_map = i;
		ft_fill_map(data);
	}
	else
		exit_handler("Found invalid line while parsing", data);
}

int	find_floor_or_ceil(t_data *data, char **file, int i)
{
	char	**nums;

	if (!ft_strncmp(file[i], "F ", 2))
	{
		nums = ft_split(file[i] + 2, ',');
		data->rfloor = ft_atoi(nums[0]);
		data->gfloor = ft_atoi(nums[1]);
		data->bfloor = ft_atoi(nums[2]);
		ft_free_array((void **)nums);
		return (1);
	}
	else if (!ft_strncmp(file[i], "C ", 2))
	{
		nums = ft_split(file[i] + 2, ',');
		data->rceil = ft_atoi(nums[0]);
		data->gceil = ft_atoi(nums[1]);
		data->bceil = ft_atoi(nums[2]);
		ft_free_array((void **)nums);
		return (1);
	}
	return (0);
}

int	find_no_or_so(t_data *data, char **file, int i)
{
	if (!ft_strncmp(file[i], "NO ", 3))
	{
		data->no_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		if (!data->no_path)
			exit_handler("ft_substr error", data);
		return (1);
	}
	else if (!ft_strncmp(file[i], "SO ", 3))
	{
		data->so_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		if (!data->so_path)
			exit_handler("ft_substr error", data);
		return (1);
	}
	return (0);
}

int	find_we_or_ea(t_data *data, char **file, int i)
{
	if (!ft_strncmp(file[i], "WE ", 3))
	{
		data->we_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		if (!data->we_path)
			exit_handler("ft_substr error", data);
		return (1);
		ft_file_check(data, file, i + 1);
	}
	else if (!ft_strncmp(file[i], "EA ", 3))
	{
		data->ea_path = ft_substr(file[i], 3, ft_strlen(file[i]) - 4);
		if (!data->ea_path)
			exit_handler("ft_substr error", data);
		return (1);
	}
	return (0);
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
