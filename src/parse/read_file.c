/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:57:44 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/04 12:13:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

void	read_file(t_game *game, const char *filename)
{
	int		fd;
	char	*line;
	int		i;

    game->map = malloc(sizeof(char *) * (count_lines(filename) + 1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}
