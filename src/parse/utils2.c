/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:08:10 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/20 14:26:35 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	line_before_map(t_r_file *file, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if ((line[i] == 'F' || line[i] == 'C') && (line[i + 1] == ' '
			|| line[i + 1] == '\t'))
		return (1);
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' '
		&& file->in_map == 0)
		return (1);
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' '
		&& file->in_map == 0)
		return (1);
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' '
		&& file->in_map == 0)
		return (1);
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' '
		&& file->in_map == 0)
		return (1);
	return (0);
}

void	exit_c_f_format(t_game *game, char *tmp, char **rgb)
{
	free(tmp);
	free(get_next_line(-1));
	if (rgb)
		free_matrix(rgb);
	cleanup_game(game);
	exit(1);
}

void	exit_parse_color(t_game *game, char **rgb, char *tmp)
{
	free_matrix(rgb);
	free(tmp);
	free(get_next_line(-1));
	cleanup_game(game);
	exit(1);
}
