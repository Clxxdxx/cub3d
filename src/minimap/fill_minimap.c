/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:35:28 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/21 14:37:06 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_square(mlx_image_t *img, int x, int y, int size, uint32_t color)
{
	int i, j;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			mlx_put_pixel(img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	fill_pixels(t_game *game, t_minimap *minimap)
{
	int	row;
	int	col;
	int	pixel_x;
	int	pixel_y;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			pixel_x = minimap->origin_x + col * minimap->scale;
			pixel_y = minimap->origin_y + row * minimap->scale;
			if (game->map[row][col] == '1')
				draw_square(game->img, pixel_x, pixel_y, minimap->scale,
					MINIMAP_WALL_COLOR);
			else
				draw_square(game->img, pixel_x, pixel_y, minimap->scale,
					MINIMAP_FLOOR_COLOR);
			col++;
		}
		row++;
	}
	minimap->player_pixel_x = minimap->origin_x + (game->player_x
			* minimap->scale);
	minimap->player_pixel_y = minimap->origin_y + (game->player_y
			* minimap->scale);
	draw_square(game->img, minimap->player_pixel_x - 2,
        minimap->player_pixel_y - 2, 4, MINIMAP_PLAYER_COLOR);
}
