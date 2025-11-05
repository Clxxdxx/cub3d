/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:57:44 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/05 15:51:47 by clalopez         ###   ########.fr       */
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

void	check_texture_elements(t_game *game, int *i)
{
	if (check_texture(game, game->map[*i], 'S', 'O') == 1)
		game->c_tex_so++;
	if (check_texture(game, game->map[*i], 'N', 'O') == 1)
		game->c_tex_no++;
	if (check_texture(game, game->map[*i], 'W', 'E') == 1)
		game->c_tex_we++;
	if (check_texture(game, game->map[*i], 'E', 'A') == 1)
		game->c_tex_ea++;
	if (check_ceiling(game, game->map[*i]) == 1)
		game->c_c_color++;
	if (check_floor(game, game->map[*i]) == 1)
		game->c_f_color++;
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
		check_floor(game, game->map[i]);
		//check_ceiling(game, game->map[i]);
		check_texture_elements(game, &i);
		i++;
		line = get_next_line(fd);
	}
	printf("s: %d\n", game->c_tex_so);
	printf("n: %d\n", game->c_tex_no);
	printf("w: %d\n", game->c_tex_we);
	printf("e: %d\n", game->c_tex_ea);
	printf("ceil: %d\n", game->c_c_color);
	printf("floor: %d\n", game->c_f_color);
	if (game->c_tex_so != 1 || game->c_tex_no != 1 || game->c_tex_we != 1
		|| game->c_tex_ea != 1 || game->c_f_color != 1 || game->c_c_color != 1)
	{
		ft_putstr_fd("Error: Repeated elements", 2);
		exit(0);
	}
	game->map[i] = NULL;
	close(fd);
}
