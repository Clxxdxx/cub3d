/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:00:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/12/03 09:45:29 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->mlx)
		mlx_terminate(game->mlx);
	cleanup_game(game);
	exit(0);
}

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

int	start_executor(t_game *game)
{
	init_player(game);
	init_mlx_window(game);
	do_raycasting(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_window, game);
	return (0);
}
