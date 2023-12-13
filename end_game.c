/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:30:59 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/13 17:03:13 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_end_game(t_data *data)
{
	int	i;

	i = 0;

	while (i < data->first_line_of_map)
		free(data->file[i++]);
	free(data->file);
	ft_free_array((void **)data->map);
	free(data->no_path);
	free(data->so_path);
	free(data->we_path);
	free(data->ea_path);
	free(data);
}
