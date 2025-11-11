/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:57:44 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/11 15:52:22 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	err_rep_elements(t_game *game, int *i)
{
	if (game->c_tex_so != 1 || game->c_tex_no != 1 || game->c_tex_we != 1
		|| game->c_tex_ea != 1 || game->c_f_color != 1 || game->c_c_color != 1)
	{
		ft_putstr_fd("Error\nExpected: 1 NO texture, 1 SO texture,"
			"1 WE texture,1 EA texture, 1 F color and 1 C color \n", 2);
		exit(0);
	}
	game->file[*i] = NULL;
}

void	err_unrec_char(t_game *game, char *trimmed, t_r_file *file)
{
	if (char_map(trimmed) == 0)
	{
		ft_putstr_fd("Error\nUnrecognized character\n", 2);
		exit(1);
	}
	game->map[file->i_map] = ft_strdup(trimmed);
	(file->i_map)++;
}

int	config_ready(t_game *game)
{
	if (game->c_tex_so == 1 && game->c_tex_no == 1 && game->c_tex_we == 1
		&& game->c_tex_ea == 1 && game->c_f_color == 1 && game->c_c_color == 1)
		return (1);
	return (0);
}

void	process_line(t_game *game, t_r_file *r_file)
{
	game->file[r_file->i_file] = r_file->trimmed;
	if (!r_file->in_map)
	{
		check_floor_ceiling(game, game->file[r_file->i_file]);
		check_texture_elements(game, &r_file->i_file);
		if (config_ready(game))
			r_file->in_map = 1;
	}
	else
		err_unrec_char(game, r_file->trimmed, r_file);
	r_file->i_file++;
}

void	read_file(t_game *game, const char *filename, t_r_file *r_file)
{
	int	fd;

	r_file->i_file = 0;
	r_file->i_map = 0;
	r_file->in_map = 0;
	game->file = malloc(sizeof(char *) * (count_lines(filename) + 1));
	game->map = malloc(sizeof(char *) * (count_lines(filename) + 1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open the map\n", 2);
		exit(1);
	}
	r_file->line = get_next_line(fd);
	while (r_file->line)
	{
		r_file->trimmed = ft_strtrim(r_file->line, "\n");
		free(r_file->line);
		process_line(game, r_file);
		r_file->line = get_next_line(fd);
	}
	close(fd);
	game->file[r_file->i_file] = NULL;
	game->map[r_file->i_map] = NULL;
	err_rep_elements(game, &r_file->i_file);
	validate_player(game);
}
