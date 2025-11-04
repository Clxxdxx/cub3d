/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:34 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/04 15:24:29 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "src/libft/libft.h"
# include "fcntl.h"

typedef struct s_rgb
{
    int     r;
    int     g;
    int     b;
}           t_rgb;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    
    char    **map;

    t_rgb   floor;
    t_rgb   ceiling;
}           t_game;



//Read file
void	read_file(t_game *game, const char *filename);

//Check textures
int	check_ceiling(t_game *game, char *line);
int	check_floor(t_game *game, char *line);

//Frees
void	free_map(char **map);


#endif