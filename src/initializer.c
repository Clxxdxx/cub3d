/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:49:22 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/04 15:30:26 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->minimap_img = NULL;
	game->player_x = 0.0;
	game->player_y = 0.0;
	game->player_angle = 0.0;
	game->player_dir = '0';
	game->file = NULL;
	game->body_map = NULL;
	game->map = NULL;
	game->c_tex_so = 0;
	game->c_tex_no = 0;
	game->c_tex_we = 0;
	game->c_tex_ea = 0;
	game->c_c_color = 0;
	game->c_f_color = 0;
	game->routes.no = NULL;
	game->routes.so = NULL;
	game->routes.we = NULL;
	game->routes.ea = NULL;
}

void	init_minimap(t_minimap *minimap)
{
	minimap->height_scale = 0;
	minimap->origin_x = 0;
	minimap->origin_y = 0;
	minimap->pixel_x = 0;
	minimap->pixel_y = 0;
	minimap->player_pixel_x = 0;
	minimap->player_pixel_y = 0;
	minimap->scale = 0;
	minimap->width_scale = 0;
}
