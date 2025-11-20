/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:39:10 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/20 12:51:28 by clalopez         ###   ########.fr       */
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

void	set_texture(t_game *game, char *route, char c1, char c2)
{
	if (c1 == 'N' && c2 == 'O')
	{
		if (game->routes.no)
			free(game->routes.no);
		game->routes.no = route;
	}
	if (c1 == 'S' && c2 == 'O')
	{
		if (game->routes.so)
			free(game->routes.so);
		game->routes.so = route;
	}
	if (c1 == 'W' && c2 == 'E')
	{
		if (game->routes.we)
			free(game->routes.we);
		game->routes.we = route;
	}
	if (c1 == 'E' && c2 == 'A')
	{
		if (game->routes.ea)
			free(game->routes.ea);
		game->routes.ea = route;
	}
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
		ft_putstr_fd("Error\nInvalid texture path\n", 2);
		free(route);
		cleanup_game(game);
		free(get_next_line(-1));
		exit(0);
	}
	close(fd);
	set_texture(game, route, c1, c2);
	return (1);
}

void	check_texture_elements(t_game *game, int *i)
{
	if (check_texture(game, game->file[*i], 'S', 'O') == 1)
		game->c_tex_so++;
	if (check_texture(game, game->file[*i], 'N', 'O') == 1)
		game->c_tex_no++;
	if (check_texture(game, game->file[*i], 'W', 'E') == 1)
		game->c_tex_we++;
	if (check_texture(game, game->file[*i], 'E', 'A') == 1)
		game->c_tex_ea++;
	if (check_ceiling(game, game->file[*i]) == 1)
		game->c_c_color++;
	if (check_floor(game, game->file[*i]) == 1)
		game->c_f_color++;
}
