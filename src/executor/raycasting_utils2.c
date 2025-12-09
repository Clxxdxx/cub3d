/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:58:40 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/09 11:08:43 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

mlx_texture_t	*set_orientation_texture(t_ray *ray, t_game *game)
{
	if (ray->wall_face == 0)
	{
		if (ray->direction_x > 0)
			return (game->textures.we);
		else
			return (game->textures.ea);
	}
	else
	{
		if (ray->direction_y > 0)
			return (game->textures.no);
		else
			return (game->textures.so);
	}
}

uint32_t	draw_rgba_pixel(mlx_texture_t *tex, t_ray *ray, int tex_y)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		pixel_index;

	pixel_index = (tex_y * tex->width + ray->tex_x) * 4;
	r = tex->pixels[pixel_index + 0];
	g = tex->pixels[pixel_index + 1];
	b = tex->pixels[pixel_index + 2];
	a = tex->pixels[pixel_index + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void	calculate_tex_coords(t_ray *ray, t_game *game, mlx_texture_t *tex,
		double *step)
{
	if (ray->wall_face == 0)
		ray->wall_x = game->player_y + ray->wall_distance * ray->direction_y;
	else
		ray->wall_x = game->player_x + ray->wall_distance * ray->direction_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * tex->width);
	if (ray->wall_face == 0 && ray->direction_x > 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	if (ray->wall_face == 1 && ray->direction_y < 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	*step = (double)tex->height / ray->wall_height;
}

void	put_pixels_ceiling(t_game *game, t_ray *ray, int *y, int x)
{
	uint32_t	ceiling_color;

	ceiling_color = (game->ceiling.r << 24) | (game->ceiling.g << 16)
		| (game->ceiling.b << 8) | 255;
	*y = 0;
	while (*y < ray->draw_from)
	{
		mlx_put_pixel(game->img, x, (*y)++, ceiling_color);
	}
}

void	put_pixels_floor(t_game *game, t_ray *ray, int *y, int x)
{
	uint32_t	floor_color;

	floor_color = (game->floor.r << 24) | (game->floor.g << 16)
		| (game->floor.b << 8) | 255;
	*y = ray->draw_to + 1;
	while (*y < WINDOW_HEIGHT)
	{
		mlx_put_pixel(game->img, x, (*y)++, floor_color);
	}
}
