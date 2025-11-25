/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/25 12:15:38 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_r_file r_file;
	//t_minimap minimap;
	
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
	// 🟦 Mostrar rutas de texturas
	printf("\n--- TEXTURAS ---\n");
	printf("NO: %s\n", game.routes.no);
	printf("SO: %s\n", game.routes.so);
	printf("WE: %s\n", game.routes.we);
	printf("EA: %s\n", game.routes.ea);
	// 🟫 Mostrar colores de suelo y cielo
	printf("\n--- COLORES ---\n");
	printf("Ceiling (C): R:%d G:%d B:%d\n", game.ceiling.r, game.ceiling.g,
		game.ceiling.b);
	printf("Floor   (F): R:%d G:%d B:%d\n", game.floor.r, game.floor.g,
		game.floor.b);
			
	// 🗺️ Mostrar mapa
	printf("\n--- MAPA ---\n");
	for (int i = 0; game.map[i]; i++)
		printf("%s\n", game.map[i]);
			
	start_executor(&game);
	create_minimap(&game);		
	
	//mlx_loop_hook(game.mlx, game)
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
