/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceilling_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:41:48 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/12 10:50:50 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parse_color_val(char *str)
{
	int	val;
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
		{
			ft_putstr_fd("Error\nColor value is invalid\n", 2);
			exit(1);
		}
		i++;
	}
	val = ft_atoi(str);
	if (val < 0 || val > 255)
	{
		ft_putstr_fd("Error\nColor value is invalid\n", 2);
		exit(1);
	}
	return (val);
}

char	*get_rgb(char *line, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	if (line[i] != c)
		return (0);
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	tmp = ft_substr(line, i, ft_strlen(line) - i);
	return (tmp);
}

int	check_ceiling(t_game *game, char *line)
{
	char	*tmp;
	char	**rgb;

	tmp = get_rgb(line, 'C');
	if (!tmp)
		return (0);
	if (ft_count_char(tmp, ',') != 2)
	{
		ft_putstr_fd("Error\nInvalid ceiling format\n", 2);
		exit(1);
	}
	rgb = ft_split(tmp, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_putstr_fd("Error\nInvalid ceiling format\n", 2);
		exit(1);
	}
	game->ceiling.r = parse_color_val(rgb[0]);
	game->ceiling.g = parse_color_val(rgb[1]);
	game->ceiling.b = parse_color_val(rgb[2]);
	free_matrix(rgb);
	free(tmp);
	return (1);
}

int	check_floor(t_game *game, char *line)
{
	char	*tmp;
	char	**rgb;

	tmp = get_rgb(line, 'F');
	if (!tmp)
		return (0);
	if (ft_count_char(tmp, ',') != 2)
	{
		ft_putstr_fd("Error\nInvalid floor format\n", 2);
		exit(1);
	}
	rgb = ft_split(tmp, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_putstr_fd("Error\nInvalid floor format\n", 2);
		exit(1);
	}
	game->floor.r = parse_color_val(rgb[0]);
	game->floor.g = parse_color_val(rgb[1]);
	game->floor.b = parse_color_val(rgb[2]);
	free_matrix(rgb);
	free(tmp);
	return (1);
}

void	check_floor_ceiling(t_game *game, char *line)
{
	check_ceiling(game, line);
	check_floor(game, line);
}
