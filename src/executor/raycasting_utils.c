/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:50:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/25 16:52:49 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	execute_dda_algorithm(t_game *game, t_ray *ray)
{
	while (ray->hit_wall == 0)
	{
		if (ray->next_side_x < ray->next_side_y)
		{
			ray->next_side_x += ray->step_distance_x;
			ray->map_position_x += ray->walk_x;
			ray->wall_face = 0;
		}
		else
		{
			ray->next_side_y += ray->step_distance_y;
			ray->map_position_y += ray->walk_y;
			ray->wall_face = 1;
		}
		if (game->map[ray->map_position_y][ray->map_position_x] == '1')
			ray->hit_wall = 1;
	}
}

void	calculate_wall_height(t_game *game, t_ray *ray)
{
	if (ray->wall_face == 0)
		ray->wall_distance = (ray->map_position_x - game->player_x
				+ (1 - ray->walk_x) / 2) / ray->direction_x;
	else
		ray->wall_distance = (ray->map_position_y - game->player_y
				+ (1 - ray->walk_y) / 2) / ray->direction_y;
	ray->wall_height = (int)(WINDOW_HEIGHT / ray->wall_distance);
	ray->draw_from = (-ray->wall_height / 2) + (WINDOW_HEIGHT / 2);
	ray->draw_to = (ray->wall_height / 2) + (WINDOW_HEIGHT / 2);
	if (ray->draw_from < 0)
		ray->draw_from = 0;
	if (ray->draw_to >= WINDOW_HEIGHT)
		ray->draw_to = WINDOW_HEIGHT - 1;
}

void	draw_wall_line(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = (game->ceiling.r << 24) | (game->ceiling.g << 16)
		| (game->ceiling.b << 8) | 255;
	floor_color = (game->floor.r << 24) | (game->floor.g << 16)
		| (game->floor.b << 8) | 255;
	y = 0;
	while (y < ray->draw_from)
		mlx_put_pixel(game->img, x, y++, ceiling_color);
	y = ray->draw_from;
	while (y <= ray->draw_to)
	{
		if (ray->wall_face == 0)
			mlx_put_pixel(game->img, x, y, 0xFF0000FF);
		else
			mlx_put_pixel(game->img, x, y, 0x00FF00FF);
		y++;
	}
	y = ray->draw_to + 1;
	while (y < WINDOW_HEIGHT)
		mlx_put_pixel(game->img, x, y++, floor_color);
}
