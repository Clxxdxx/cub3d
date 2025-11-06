/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/06 12:24:04 by clalopez         ###   ########.fr       */
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
	check_file_extension(argv[1]);
	read_file(&game, argv[1]);
	free_matrix(game.map);
	free(game.routes.so);
	free(game.routes.no);
	free(game.routes.we);
	free(game.routes.ea);
	return (0);
}
