/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:34 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/17 17:50:13 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "fcntl.h"
# include "src/libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>


# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# define KEY_ESC MLX_KEY_ESCAPE
# define KEY_W MLX_KEY_W
# define KEY_A MLX_KEY_A
# define KEY_S MLX_KEY_S
# define KEY_D MLX_KEY_D
# define KEY_LEFT MLX_KEY_LEFT
# define KEY_RIGHT MLX_KEY_RIGHT

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.1
# define PI 3.14159265359

# define FOV 1.047197551	//pi / 3

//PUTISIMA NORMINETTE
typedef struct s_r_file
{
	char		*line;
	char		*trimmed;
	int			i_file;
	int			i_map;
	int			in_map;
}				t_r_file;

typedef struct s_routes
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_routes;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	//javier
	double		player_x;
	double		player_y;
	double		player_angle;
	char		player_dir;

	char		**file;
	char		**body_map;
	char		**map;
	int			c_tex_so;
	int			c_tex_no;
	int			c_tex_we;
	int			c_tex_ea;
	int			c_f_color;
	int			c_c_color;
	t_routes	routes;
	t_rgb		floor;
	t_rgb		ceiling;
}				t_game;

typedef struct s_ray
{
	double		direction_x;			//posicion a la que apunta x
	double		direction_y;			//posicion a la que apunta y

	double		step_step_distance_x;	//cuanto avanza para cruzar 1 casilla en x
	double		step_step_distance_y;	//cuanto avanza para cruzar 1 casilla en y

	double		next_wall_x;			//distancia hasta la próxima linea vertical
	double		next_wall_y;			//distancia hasta la próxima linea horizontal

	double		wall_distance;			//distancia final a la pared

	int			position_x;				//posicion en la que estamos actual
	int			position_y;				//posicion en la que estamos actual

	int			walk_y;					//dirección del paso
	int			walk_x;					//direccion del paso

	int			hit_wall;				//declarar si ha tocado una pared o no
	int			wall_face;				//que cara de la pared es;

	int			wall_height;			//altura de la linea a dibujar
	int			draw_from;				//pixel donde empezar
	int			draw_to;				//pixel donde terminar
}		t_ray;


void			init_game(t_game *game);

// Read file
void	read_file(t_game *game, const char *filename, t_r_file *file);

// Check errors
int				check_ceiling(t_game *game, char *line);
int				check_floor(t_game *game, char *line);
void			check_texture_elements(t_game *game, int *i);
int				check_texture(t_game *game, char *line, char c1, char c2);
void			check_file_extension(char *filename);
void			check_floor_ceiling(t_game *game, char *line);
int				get_max_width(char **map);
int				check_texture(t_game *game, char *line, char c1, char c2);
void			complete_with_x(char **map);
int				char_map(char *line);
int				count_lines(const char *filename);
int				get_max_width(char **map);
void			validate_player(t_game *game);
void			validate_closed_map(t_game *game);
char			**dup_map(char **map);
void 			map_trimmed(t_game *game);
int				line_before_map(t_r_file *file, char *line);
int 			is_empty_line(char *line);


// Frees
void			free_matrix(char **mtx);
int				config_ready(t_game *game);
void			cleanup_game(t_game *game);

// Player
void			init_player(t_game *game);
void			move_player(t_game *game, int keycode);
int				is_valid_move(t_game *game, double new_x, double new_y);
void			rotate_player(t_game *game, int keycode);
void			move_forward_back(t_game *game, int keycode, double *new_x, double *new_y);
void			move_strafe(t_game *game, int keycode, double *new_x, double *new_y);

// Executor
int				start_executor(t_game *game);
void			init_mlx_window(t_game *game);
void			close_window(void *param);
void			key_hook(mlx_key_data_t keydata, void *param);
void			draw_player_info(t_game *game);
void	perform_raycasting(t_game *game);

#endif