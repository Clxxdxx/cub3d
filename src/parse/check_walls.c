/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:47:30 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/11 14:33:12 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_rows(char **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

void	fill_empty(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	str[len] = '\0';
}

void	fill_map_borders(char **map, int *j, int cols, int rows)
{
	int	i;

	i = 0;
	while (map[*j][i])
	{
		if (j == 0 && map[*j][i] == ' ')
			map[*j][i] = 'X';
		if (*j == rows - 1 && map[*j][i] == ' ')
			map[*j][i] = 'X';
		if (i == 0 && map[*j][i] == ' ')
			map[*j][i] = 'X';
		if (i == cols - 1 && map[*j][i] == ' ')
			map[*j][i] = 'X';
		i++;
	}
	(*j)++;
}

void	fill_first_last_row(char **map, int rows)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == ' ')
			map[0][i] = 'X';
		i++;
	}
	i = 0;
	while (map[rows - 1][i])
	{
		if (map[rows - 1][i] == ' ')
			map[rows - 1][i] = 'X';
		i++;
	}
}

void	complete_with_x(char **map)
{
	int		i;
	int		j;
	int		rows;
	int		cols;
	char	*tmp;

	rows = get_rows(map);
	cols = get_max_width(map);
	j = 0;
	while (map[j])
	{
		tmp = map[j];
		map[j] = malloc(cols + 1);
		i = 0;
		while (tmp[i])
		{
			map[j][i] = tmp[i];
			i++;
		}
		free(tmp);
		map[j][i] = '\0';
		fill_empty(map[j], cols);
		fill_map_borders(map, &j, cols, rows);
	}
	fill_first_last_row(map, rows);
}
