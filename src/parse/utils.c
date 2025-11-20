/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:53:56 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/20 12:08:28 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	char_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != ' '
			&& line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	count_lines_map(const char *filename)
{
	int		fd;
	char	*line;
	int		count;
	int		in_map;

	in_map = 0;
	fd = open(filename, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (char_map(line) == 1)
			in_map = 1;
		if (in_map == 1)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count == 0)
	{
		ft_putstr_fd("Error\nMap not found in file\n", 2);
		exit(1);
	}
	return (count);
}

int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	get_max_width(char **map)
{
	int	i;
	int	j;
	int	max;

	j = 0;
	max = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		if (i > max)
			max = i;
		j++;
	}
	return (max);
}

void	validate_player(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (game->body_map[i])
	{
		j = 0;
		while (game->body_map[i][j])
		{
			if (game->body_map[i][j] == 'N' || game->body_map[i][j] == 'S'
				|| game->body_map[i][j] == 'E' || game->body_map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		ft_putstr_fd("Error\nMap must have only one player start position(W, A,"
			" S, D)\n", 2);
		cleanup_game(game);
		exit(1);
	}
}
