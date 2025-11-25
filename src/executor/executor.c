/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:00:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/25 12:16:45 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
abrir la ventana
*/
void	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nMLX initialization failed\n", 2);
		exit(1);
	}
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img)
	{
		ft_putstr_fd("Error\nImage creation failed\n", 2);
		mlx_terminate(game->mlx);
		exit(1);
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

/*
cerrar la ventana
*/
void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->mlx)
		mlx_terminate(game->mlx);
	cleanup_game(game);
	exit(0);
}

/*
manejar las teclas
*/
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(param);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D
			|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
			&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		move_player(game, keydata.key);
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		mlx_image_to_window(game->mlx, game->img, 0, 0);
		do_raycasting(game);
		fill_pixels(game, &game->minimap);
    	mlx_image_to_window(game->mlx, game->minimap_img, 0, 0);
	}
}

/*
esto no vale, solo es para poner mensajes en pantalla
*/
void	draw_player_info(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			mlx_put_pixel(game->img, x + 50, y + 50, 0x000000FF);
			x++;
		}
		y++;
	}
	mlx_put_pixel(game->img, (int)game->player_x * 10 + 50, 
		(int)game->player_y * 10 + 50, 0x00FF00FF);
}

/*

*/
int	start_executor(t_game *game)
{
	init_player(game);
	init_mlx_window(game);
	do_raycasting(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_window, game);
	draw_player_info(game);
	//El loop tiene que ir en el main porque sino bloquea la ejecucion
	//y no crea el minimapa
	//mlx_loop(game->mlx);
	return (0);
}
