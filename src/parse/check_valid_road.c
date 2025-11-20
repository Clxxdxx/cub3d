/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_road.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:05:33 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/20 12:06:10 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	map_height(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

char	**dup_map(char **map)
{
	int		i;
	int		height;
	char	**copy;

	height = map_height(map);
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_matrix(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == ' ' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	map[y][x] = 'F';
	if (!flood_fill(map, x + 1, y))
		return (0);
	if (!flood_fill(map, x - 1, y))
		return (0);
	if (!flood_fill(map, x, y + 1))
		return (0);
	if (!flood_fill(map, x, y - 1))
		return (0);
	return (1);
}

void	validate_closed_map(t_game *game)
{
	char	**copy;
	int		player_x;
	int		player_y;

	copy = dup_map(game->body_map);
	find_player(copy, &player_x, &player_y);
	if (flood_fill(copy, player_x, player_y) == 0)
	{
		ft_putstr_fd("Error\nMap is not closed\n", 2);
		free_matrix(copy);
		cleanup_game(game);
		exit(1);
	}
	free_matrix(copy);
}
