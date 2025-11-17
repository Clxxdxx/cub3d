/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:30:00 by jbogad            #+#    #+#             */
/*   Updated: 2025/11/17 17:50:23 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	print_map(t_game *game, int x, int y)
{
	x = 0;
	y = 0;
	
	while(y < WINDOW_HEIGHT)
	{
		while(x < WINDOW_WIDTH)
		{
			mlx_put_pixel(game->img, x, y, 0x00000FF);
			x++;
		}
		y++;
	}

}

void	perform_raycasting(t_game *game)
{
	//t_ray	ray;
	//int		x;

	print_map(game, 0, 0);

}