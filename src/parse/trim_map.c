/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:22:45 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/20 12:33:52 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	valid_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	count_valid_lines(t_game *game)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (game->body_map[i])
	{
		if (valid_line(game->body_map[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	process_map_line(t_game *game, int *in_map, int *i, int *j)
{
	if (valid_line(game->body_map[*j]) == 1 && (*in_map == 0 || *in_map == 1))
	{
		game->map[*i] = ft_strdup(game->body_map[*j]);
		*in_map = 1;
		(*i)++;
	}
	if (is_empty_line(game->body_map[*j]) == 0 && *in_map == 1)
		*in_map = 2;
	if (is_empty_line(game->body_map[*j]) == 1 && *in_map == 2)
	{
		ft_putstr_fd("Error\nMap must be the last element of the file\n", 2);
		cleanup_game(game);
		exit(1);
	}
	(*j)++;
}

void	map_trimmed(t_game *game)
{
	int	j;
	int	i;
	int	count;
	int	in_map;

	in_map = 0;
	count = count_valid_lines(game);
	game->map = ft_calloc(count + 1, sizeof(char *));
	if (!game->map)
		return ;
	i = 0;
	j = 0;
	while (game->body_map[j])
		process_map_line(game, &in_map, &i, &j);
	game->map[i] = NULL;
}
