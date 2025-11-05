/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/05 15:46:48 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game game;
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
    init_game(&game);
	read_file(&game, argv[1]);
	check_floor(&game, game.map[0]);
	printf("Floor\nr: %d\ng: %d\nb: %d\n", game.floor.r, game.floor.g,
		game.floor.b);
    check_ceiling(&game, game.map[5]);
	printf("Ceiling\nr: %d\ng: %d\nb: %d\n", game.ceiling.r, game.ceiling.g,
		game.ceiling.b);
	/* check_texture(&game, game.map[1], 'S', 'O');
	check_texture(&game, game.map[2], 'N', 'O');
	check_texture(&game, game.map[3], 'W', 'E');
	check_texture(&game, game.map[4], 'E', 'A'); */
	printf("SO: %s\n", game.routes.so);
	printf("NO: %s\n", game.routes.no);
	printf("WE: %s\n", game.routes.we);
	printf("EA: %s\n", game.routes.ea);
	free_matrix(game.map);
	free(game.routes.so);
	free(game.routes.no);
	free(game.routes.we);
	free(game.routes.ea);
	return (0);
}