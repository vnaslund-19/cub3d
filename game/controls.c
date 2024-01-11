/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:13:23 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/11 14:30:22 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game *game)
{
	(void)game;
	printf("Forward movement detected\n");
}

void	move_backward(t_game *game)
{
	(void)game;
	printf("Backward movement detected\n");
}

void	move_left(t_game *game)
{
	(void)game;
	printf("Left movement detected\n");
}

void	move_right(t_game *game)
{
	(void)game;
	printf("Right movement detected\n");
}

void	rotate_left(t_game *game)
{
	(void)game;
	printf("Left rotation detected\n");
}

void	rotate_right(t_game *game)
{
	(void)game;
	printf("Right rotation detected\n");
}
