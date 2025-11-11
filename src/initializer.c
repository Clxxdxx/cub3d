/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:49:22 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/11 11:35:57 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_game(t_game *game)
{
	game->file = NULL;
	game->map = NULL;
	game->c_tex_so = 0;
	game->c_tex_no = 0;
	game->c_tex_we = 0;
	game->c_tex_ea = 0;
	game->c_c_color = 0;
	game->c_f_color = 0;
}
