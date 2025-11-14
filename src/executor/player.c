/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:30:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/14 11:48:31 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

static void	set_player_position(t_game *game, int x, int y)
{
	game->player_x = x + 0.5;
	game->player_y = y + 0.5;
	game->player_dir = game->map[y][x];
	if (game->player_dir == 'N')
		game->player_angle = 4.71;
	else if (game->player_dir == 'S')
		game->player_angle = 1.57;
	else if (game->player_dir == 'E')
		game->player_angle = 0.0;
	else
		game->player_angle = 3.14;
	game->map[y][x] = '0';
}

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				set_player_position(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
	ft_putstr_fd("Error\nNo player found in map\n", 2);
	exit(1);
}

int	is_valid_move(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_y < 0 || !game->map[map_y] || map_x < 0
		|| !game->map[map_y][map_x] || game->map[map_y][map_x] == '\0')
		return (0);
	if (game->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		rotate_player(game, keycode);
		return ;
	}
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_W || keycode == KEY_S)
		move_forward_back(game, keycode, &new_x, &new_y);
	else if (keycode == KEY_A || keycode == KEY_D)
		move_strafe(game, keycode, &new_x, &new_y);
	if (is_valid_move(game, new_x, new_y))
	{
		game->player_x = new_x;
		game->player_y = new_y;
	}
}
