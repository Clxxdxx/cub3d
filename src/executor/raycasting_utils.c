/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:50:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/28 11:25:49 by clalopez         ###   ########.fr       */
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

void	calculate_wall_height(t_game *game, t_ray *ray, int x)
{
	double	camera_x;
	double	ray_angle;

	if (ray->wall_face == 0)
		ray->wall_distance = (ray->map_position_x - game->player_x + (1
					- ray->walk_x) / 2) / ray->direction_x;
	else
		ray->wall_distance = (ray->map_position_y - game->player_y + (1
					- ray->walk_y) / 2) / ray->direction_y;
	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray_angle = game->player_angle + atan(camera_x * tan(FOV / 2));
	ray->wall_distance *= cos(ray_angle - game->player_angle);
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
	mlx_texture_t	*tex;
	double			step;
	double			tex_pos;
	int				y;
	int				tex_y;

	tex = set_orientation_texture(ray, game);
	put_pixels_ceiling(game, ray, &y, x);
	calculate_tex_coords(ray, game, tex, &step);
	tex_pos = (ray->draw_from - WINDOW_HEIGHT / 2 + ray->wall_height / 2)
		* step;
	y = ray->draw_from;
	while (y <= ray->draw_to)
	{
		tex_y = (int)tex_pos % tex->height;
		if (tex_y < 0)
			tex_y += tex->height;
		tex_pos += step;
		mlx_put_pixel(game->img, x, y, draw_rgba_pixel(tex, ray, tex_y));
		y++;
	}
	put_pixels_floor(game, ray, &y, x);
}
