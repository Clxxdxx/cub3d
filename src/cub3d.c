/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/04 15:24:15 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int argc, char **argv)
{
    t_game game;
    if (argc != 2)
    {
        ft_printf("Error\n");
        return 0;
    }
    read_file(&game, argv[1]);
    check_floor(&game, game.map[0]);
    printf("Floor\nr: %d\ng: %d\nb: %d\n", game.floor.r, game.floor.g, game.floor.b);
    check_ceiling(&game, game.map[5]);
    printf("Ceiling\nr: %d\ng: %d\nb: %d\n", game.ceiling.r, game.ceiling.g, game.ceiling.b);
    free_map(game.map);
    return 0;
}