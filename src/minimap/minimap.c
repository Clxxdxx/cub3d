/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:42:29 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/25 15:17:26 by clalopez         ###   ########.fr       */
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
	int		row;
	int		col;
	int		pixel_x;
	int		pixel_y;
	int		max_width;
	int		len;
	char	tile;

	max_width = get_max_width(game->map);
	row = 0;
	while (game->map[row])
	{
		len = ft_strlen(game->map[row]);
		col = 0;
		while (col < max_width)
		{
			if (col < len)
				tile = game->map[row][col];
			else
				tile = ' ';
			pixel_x = minimap->origin_x + col * minimap->scale;
			pixel_y = minimap->origin_y + row * minimap->scale;
			if (tile == '1' || tile == ' ')
				draw_square(game->minimap_img, pixel_x, pixel_y, minimap->scale,
					MINIMAP_WALL_COLOR);
			else
				draw_square(game->minimap_img, pixel_x, pixel_y, minimap->scale,
					MINIMAP_FLOOR_COLOR);
			col++;
		}
		row++;
	}
	minimap->player_pixel_x = minimap->origin_x + (game->player_x
			* minimap->scale);
	minimap->player_pixel_y = minimap->origin_y + (game->player_y
			* minimap->scale);
	draw_square(game->minimap_img, minimap->player_pixel_x - 2,
		minimap->player_pixel_y - 2, 6, MINIMAP_PLAYER_COLOR);
}

void	create_minimap(t_game *game)
{
	calculate_ceil_px_minimap(game, &game->minimap);
	game->minimap_img = mlx_new_image(game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	mlx_image_to_window(game->mlx, game->minimap_img, 0, 0);
	fill_pixels(game, &game->minimap);
}
