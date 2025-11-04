/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceilling_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:41:48 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/04 15:56:53 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parse_color_val(char *str)
{
	int	val;

	val = ft_atoi(str);
	if (val < 0 || val > 255)
	{
		ft_putstr_fd("Error: Color value is invalid", 2);
		exit(1);
	}
	return (val);
}

int	check_ceiling(t_game *game, char *line)
{
	int		i;
	char	*tmp;
	char	**rgb;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	if (line[i] != 'C')
		return (0);
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	tmp = ft_substr(line, i, ft_strlen(line) - i);
	if (!tmp)
		return (0);
    if (ft_count_char(tmp, ',') > 2)
    {
		ft_putstr_fd("Error: Invalid floor format\n", 2);
		exit(1);
	} 
	rgb = ft_split(tmp, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_putstr_fd("Error: Invalid ceiling format\n", 2);
		exit(1);
	}
	game->ceiling.r = parse_color_val(rgb[0]);
	game->ceiling.g = parse_color_val(rgb[1]);
	game->ceiling.b = parse_color_val(rgb[2]);
	//free_split(rgb);
	free(tmp);
	return (1);
}

int	check_floor(t_game *game, char *line)
{
	int		i;
	char	*tmp;
	char	**rgb;
	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	if (line[i] != 'F')
		return (0);
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	tmp = ft_substr(line, i, ft_strlen(line) - i);
	if (!tmp)
		return (0);
    if (ft_count_char(tmp, ',') > 2)
    {
		ft_putstr_fd("Error: Invalid floor format\n", 2);
		exit(1);
	} 
	rgb = ft_split(tmp, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_putstr_fd("Error: Invalid floor format\n", 2);
		exit(1);
	}
	game->floor.r = parse_color_val(rgb[0]);
	game->floor.g = parse_color_val(rgb[1]);
	game->floor.b = parse_color_val(rgb[2]);
	//free_split(rgb);
	free(tmp);
	return (1);
}
