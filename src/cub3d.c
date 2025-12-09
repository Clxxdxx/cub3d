/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/09 11:20:14 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_r_file	r_file;

	if (argc != 2)
	{
		ft_printf("Error\nExecute: ./cub3d maps/map.cub\n");
		return (0);
	}
	init_game(&game);
	init_minimap(&game.minimap);
	check_file_extension(argv[1]);
	read_file(&game, argv[1], &r_file);
	validate_closed_map(&game);
	map_trimmed(&game);
	game.textures.no = mlx_load_png(game.routes.no);
	game.textures.so = mlx_load_png(game.routes.so);
	game.textures.we = mlx_load_png(game.routes.we);
	game.textures.ea = mlx_load_png(game.routes.ea);
	start_executor(&game);
	create_minimap(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
