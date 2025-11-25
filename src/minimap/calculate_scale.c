/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:58:22 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/25 14:28:12 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_height_map(t_game *game)
{
	int	j;

	j = 0;
	while (game->map[j])
		j++;
	return (j);
}

int	get_width_map(t_game *game)
{
	int	max;
	int	j;
	int	i;

	max = 0;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
			i++;
		if (i > max)
			max = i;
		j++;
	}
	return (max);
}

int	min(int width, int height)
{
	if (width < height)
		return (width);
	else if (width > height)
		return (height);
	else
		return (width);
}

void	calculate_ceil_px_minimap(t_game *game, t_minimap *minimap)
{
	minimap->width_scale = MINIMAP_WIDTH / get_width_map(game);
	minimap->height_scale = MINIMAP_HEIGHT / get_height_map(game);
	minimap->scale = min(minimap->width_scale, minimap->height_scale);
}
