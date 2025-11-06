/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:48:07 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/06 14:28:13 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_file_extension(char *filename)
{
	int		len;
	char	*after;

	after = ft_strrchr(filename, '/');
	if (!after)
		after = filename;
	else
		after++;
	if (ft_strlen(after) <= 4)
	{
		ft_putstr_fd("Error\nFilename is invalid\n", 2);
		exit(1);
	}
	len = ft_strlen(filename);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid extension\n", 2);
		exit(1);
	}
}
