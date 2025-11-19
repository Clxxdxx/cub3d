/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:14:55 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/19 14:08:54 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_matrix(char **mtx)
{
	int	i;

	if (!mtx)
		return ;
	i = 0;
	while (mtx[i])
	{
		if (mtx[i])
			free(mtx[i]);
		i++;
	}
	free(mtx);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->file)
		free_matrix(game->file);
	if (game->body_map)
		free_matrix(game->body_map);
	if (game->map)
		free_matrix(game->map);
	if (game->routes.so)
		free(game->routes.so);
	if (game->routes.no)
		free(game->routes.no);
	if (game->routes.we)
		free(game->routes.we);
	if (game->routes.ea)
		free(game->routes.ea);
}
