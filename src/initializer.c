/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:49:22 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/14 11:48:31 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_game(t_game *game)
{
	// Inicializar punteros MLX
	game->mlx = NULL;
	game->img = NULL;
	
	// Inicializar datos del jugador
	game->player_x = 0.0;
	game->player_y = 0.0;
	game->player_angle = 0.0;
	game->player_dir = '0';
	
	// Inicializar parsing
	game->file = NULL;
	game->body_map = NULL;
	game->map = NULL;
	game->c_tex_so = 0;
	game->c_tex_no = 0;
	game->c_tex_we = 0;
	game->c_tex_ea = 0;
	game->c_c_color = 0;
	game->c_f_color = 0;
	
	// Inicializar rutas
	game->routes.no = NULL;
	game->routes.so = NULL;
	game->routes.we = NULL;
	game->routes.ea = NULL;
}
