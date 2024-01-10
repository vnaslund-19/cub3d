/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:30:59 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 17:51:00 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_end_game(t_game *game)
{
	ft_free_array((void **)game->data->file);
	ft_free_array((void **)game->data->map);
	free(game->data->no_path);
	free(game->data->so_path);
	free(game->data->we_path);
	free(game->data->ea_path);
	free(game->data);
	free(game);
}
