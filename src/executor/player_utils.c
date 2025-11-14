/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:00:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/14 11:48:31 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotate_player(t_game *game, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		game->player_angle -= ROT_SPEED;
		if (game->player_angle < 0)
			game->player_angle += 2 * PI;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player_angle += ROT_SPEED;
		if (game->player_angle >= 2 * PI)
			game->player_angle -= 2 * PI;
	}
}

void	move_forward_back(t_game *game, int keycode, double *new_x,
		double *new_y)
{
	double	move_x;
	double	move_y;

	move_x = cos(game->player_angle) * MOVE_SPEED;
	move_y = sin(game->player_angle) * MOVE_SPEED;
	if (keycode == KEY_W)
	{
		*new_x += move_x;
		*new_y += move_y;
	}
	else if (keycode == KEY_S)
	{
		*new_x -= move_x;
		*new_y -= move_y;
	}
}

void	move_strafe(t_game *game, int keycode, double *new_x, double *new_y)
{
	double	move_x;
	double	move_y;

	if (keycode == KEY_A)
	{
		move_x = cos(game->player_angle - (PI / 2)) * MOVE_SPEED;
		move_y = sin(game->player_angle - (PI / 2)) * MOVE_SPEED;
	}
	else
	{
		move_x = cos(game->player_angle + (PI / 2)) * MOVE_SPEED;
		move_y = sin(game->player_angle + (PI / 2)) * MOVE_SPEED;
	}
	*new_x += move_x;
	*new_y += move_y;
}
