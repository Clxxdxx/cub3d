/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:34 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/05 15:37:17 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "src/libft/libft.h"
# include "fcntl.h"

typedef struct s_routes
{
    char     *no;
    char     *so;
    char     *we;
    char     *ea;
}           t_routes;

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
    int     c_tex_so;
    int     c_tex_no;
    int     c_tex_we;
    int     c_tex_ea;
    int     c_f_color;
    int     c_c_color;
    t_routes routes;
    t_rgb   floor;
    t_rgb   ceiling;
}           t_game;


void init_game(t_game *game);

//Read file
void	read_file(t_game *game, const char *filename);

//Check textures
int	check_ceiling(t_game *game, char *line);
int	check_floor(t_game *game, char *line);
int check_texture(t_game *game, char *line, char c1, char c2);

//Frees
void	free_matrix(char **mtx);


#endif