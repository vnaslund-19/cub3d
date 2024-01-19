/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:13:23 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/12 17:55:27 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player(t_game *game, double newx, double newy)
{
	if (game->data->map[(int)game->player->y]
		[(int)(newx + COLLISION_MARGIN)] != WALL
		&& game->data->map[(int)game->player->y]
		[(int)(newx - COLLISION_MARGIN)] != WALL)
		game->player->x = newx;
	if (game->data->map[(int)(newy + COLLISION_MARGIN)]
		[(int)game->player->x] != WALL
		&& game->data->map[(int)(newy - COLLISION_MARGIN)]
		[(int)game->player->x] != WALL)
		game->player->y = newy;
}

void	move_forward(t_game *game)
{
	double	newx;
	double	newy;

	newx = game->player->x + (game->player->x_viewdir * MOVE_SPEED);
	newy = game->player->y + (game->player->y_viewdir * MOVE_SPEED);
	move_player(game, newx, newy);
}

void	move_backward(t_game *game)
{
	double	newx;
	double	newy;

	newx = game->player->x - (game->player->x_viewdir * MOVE_SPEED);
	newy = game->player->y - (game->player->y_viewdir * MOVE_SPEED);
	move_player(game, newx, newy);
}

void	move_left(t_game *game)
{
	double	newx;
	double	newy;

	newx = game->player->x + (game->player->y_viewdir * MOVE_SPEED);
	newy = game->player->y - (game->player->x_viewdir * MOVE_SPEED);
	move_player(game, newx, newy);
}

void	move_right(t_game *game)
{
	double	newx;
	double	newy;

	newx = game->player->x - (game->player->y_viewdir * MOVE_SPEED);
	newy = game->player->y + (game->player->x_viewdir * MOVE_SPEED);
	move_player(game, newx, newy);
}
