/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:30:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/28 11:17:45 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	init_ray_of_column(t_game *game, t_ray *ray, int x)
{
	double	camera_x;
	double	ray_angulo;

	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray_angulo = game->player_angle + atan(camera_x * tan(FOV / 2));
	ray->direction_x = cos(ray_angulo);
	ray->direction_y = sin(ray_angulo);
	ray->step_distance_x = fabs(1 / ray->direction_x);
	ray->step_distance_y = fabs(1 / ray->direction_y);
	ray->map_position_x = (int)game->player_x;
	ray->map_position_y = (int)game->player_y;
	ray->hit_wall = 0;
	if (ray->direction_x < 0)
	{
		ray->walk_x = -1;
		ray->next_side_x = (game->player_x - ray->map_position_x)
			* ray->step_distance_x;
	}
	else
	{
		ray->walk_x = 1;
		ray->next_side_x = (ray->map_position_x + 1.0 - game->player_x)
			* ray->step_distance_x;
	}
}

static	void	init_ray_of_column_y(t_game *game, t_ray *ray)
{
	if (ray->direction_y < 0)
	{
		ray->walk_y = -1;
		ray->next_side_y = (game->player_y - ray->map_position_y)
			* ray->step_distance_y;
	}
	else
	{
		ray->walk_y = 1;
		ray->next_side_y = (ray->map_position_y + 1.0 - game->player_y)
			* ray->step_distance_y;
	}
}

void	do_raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray_of_column(game, &ray, x);
		init_ray_of_column_y(game, &ray);
		execute_dda_algorithm(game, &ray);
		calculate_wall_height(game, &ray, x);
		draw_wall_line(game, &ray, x);
		x++;
	}
}
