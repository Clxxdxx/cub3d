/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:00:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/13 17:14:20 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
abrir la ventana
*/
void	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nMLX initialization failed\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!game->win)
	{
		ft_putstr_fd("Error\nWindow creation failed\n", 2);
		exit(1);
	}
}
/*
cerrar la ventana
*/
int	close_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	cleanup_game(game);
	exit(0);
	return (0);
}

/*
manejar las teclas
*/
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		move_player(game, keycode);
		mlx_clear_window(game->mlx, game->win);
		draw_player_info(game);
	}
	return (0);
}

/*
esto no vale, solo es para poner mensajes en pantalla
*/
void	draw_player_info(t_game *game)
{
	mlx_string_put(game->mlx, game->win, 500, 200, 0xFFFFFF, "hola soy javier");
	mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFF, "cub3D");
	mlx_string_put(game->mlx, game->win, 50, 80, 0x00FF00,
		"WASD = mover, flechas = rotar, ESC = salir");
}

/*

*/
int	start_executor(t_game *game)
{
	init_player(game);
	init_mlx_window(game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_clear_window(game->mlx, game->win);
	draw_player_info(game);
	mlx_loop(game->mlx);
	return (0);
}
