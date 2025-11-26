/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:42:29 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/26 14:45:50 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_square(mlx_image_t *img, t_square sq)
{
	int	i;
	int	j;

	j = 0;
	while (j < sq.size)
	{
		i = 0;
		while (i < sq.size)
		{
			mlx_put_pixel(img, sq.x + i, sq.y + j, sq.color);
			i++;
		}
		j++;
	}
}

void	print_wall_floor(t_square sq, t_game *game, char tile, int *col)
{
	if (tile == '1' || tile == ' ')
	{
		sq.color = MINIMAP_WALL_COLOR;
		draw_square(game->minimap_img, sq);
	}
	else
	{
		sq.color = MINIMAP_FLOOR_COLOR;
		draw_square(game->minimap_img, sq);
	}
	(*col)++;
}

void	print_player(t_square sq, t_game *game, t_minimap *minimap)
{
	sq.x = (minimap->origin_x + (game->player_x * minimap->scale)) - 2;
	sq.y = (minimap->origin_y + (game->player_y * minimap->scale)) - 2;
	sq.color = MINIMAP_PLAYER_COLOR;
	sq.size = 6;
	draw_square(game->minimap_img, sq);
}

void	fill_pixels(t_game *game, t_minimap *minimap)
{
	int			row;
	int			col;
	int			len;
	char		tile;
	t_square	sq;

	row = 0;
	while (game->map[row])
	{
		len = ft_strlen(game->map[row]);
		col = 0;
		while (col < get_max_width(game->map))
		{
			if (col < len)
				tile = game->map[row][col];
			else
				tile = ' ';
			sq.x = minimap->origin_x + col * minimap->scale;
			sq.y = minimap->origin_y + row * minimap->scale;
			sq.size = minimap->scale;
			print_wall_floor(sq, game, tile, &col);
		}
		row++;
	}
	print_player(sq, game, minimap);
}

void	create_minimap(t_game *game)
{
	calculate_ceil_px_minimap(game, &game->minimap);
	game->minimap_img = mlx_new_image(game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	mlx_image_to_window(game->mlx, game->minimap_img, 0, 0);
	fill_pixels(game, &game->minimap);
}
