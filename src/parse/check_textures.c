/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:39:10 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/05 14:13:07 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*get_path(char *line, char c1, char c2)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	if (line[i] != c1 || line[i + 1] != c2)
		return (NULL);
	i += 2;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	tmp = ft_substr(line, i, ft_strlen(line) - i);
	return (tmp);
}

int	check_texture(t_game *game, char *line, char c1, char c2)
{
	char	*route;
	int		fd;

	route = get_path(line, c1, c2);
	if (!route)
		return (0);
	fd = open(route, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Invalid texture path\n", 2);
		free(route);
		exit(0);
	}
	close(fd);
	if (c1 == 'N' && c2 == 'O')
		game->routes.no = route;
	if (c1 == 'S' && c2 == 'O')
		game->routes.so = route;
	if (c1 == 'W' && c2 == 'E')
		game->routes.we = route;
	if (c1 == 'E' && c2 == 'A')
		game->routes.ea = route;
	return (1);
}
