/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:58:34 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/04 15:52:49 by clalopez         ###   ########.fr       */
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

# define FOV 1.047197551

# define MINIMAP_WIDTH 400
# define MINIMAP_HEIGHT 400
# define MINIMAP_WALL_COLOR 0x804000FF
# define MINIMAP_PLAYER_COLOR 0xFE0000FF
# define MINIMAP_FLOOR_COLOR 0xCDCDCDFF

typedef struct s_r_file
{
	char	*line;
	char	*trimmed;
	int		i_file;
	int		i_map;
	int		in_map;
}			t_r_file;

typedef struct s_routes
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_routes;

typedef struct s_textures
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}					t_textures;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_minimap
{
	int	width_scale;
	int	height_scale;
	int	scale;
	int	origin_x;
	int	origin_y;
	int	pixel_x;
	int	pixel_y;
	int	player_pixel_x;
	int	player_pixel_y;
}		t_minimap;

typedef struct s_square
{
	int			x;
	int			y;
	int			size;
	uint32_t	color;
}				t_square;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*minimap_img;
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
	t_textures	textures;
	t_routes	routes;
	t_rgb		floor;
	t_rgb		ceiling;
	t_minimap	minimap;
}				t_game;

typedef struct s_ray
{
	double	direction_x;
	double	direction_y;
	double	step_distance_x;
	double	step_distance_y;
	double	next_side_x;
	double	next_side_y;
	double	wall_distance;
	int		map_position_x;
	int		map_position_y;
	int		walk_y;
	int		walk_x;
	int		hit_wall;
	int		wall_face;
	int		wall_height;
	int		draw_from;
	int		draw_to;
	double	wall_x;
	int		tex_x;
}			t_ray;

void			init_game(t_game *game);
void			init_minimap(t_minimap *minimap);
void			read_file(t_game *game, const char *filename, t_r_file *file);
int				check_ceiling(t_game *game, char *line);
int				check_floor(t_game *game, char *line);
void			check_texture_elements(t_game *game, int *i);
int				check_texture(t_game *game, char *line, char c1, char c2);
void			check_file_extension(char *filename);
void			check_floor_ceiling(t_game *game, char *line);
void			exit_c_f_format(t_game *game, char *tmp, char **rgb);
void			exit_parse_color(t_game *game, char **rgb, char *tmp);
int				get_max_width(char **map);
int				char_map(char *line);
int				count_lines(const char *filename);
void			validate_player(t_game *game);
void			validate_closed_map(t_game *game);
char			**dup_map(char **map);
void			map_trimmed(t_game *game);
int				line_before_map(t_r_file *file, char *line);
int				is_empty_line(char *line);
void			free_matrix(char **mtx);
int				config_ready(t_game *game);
void			cleanup_game(t_game *game);
void			init_player(t_game *game);
void			move_player(t_game *game, int keycode);
int				is_valid_move(t_game *game, double new_x, double new_y);
void			rotate_player(t_game *game, int keycode);
void			move_forward_back(t_game *game, int keycode, double *new_x,
					double *new_y);
void			move_strafe(t_game *game, int keycode, double *new_x,
					double *new_y);
int				start_executor(t_game *game);
void			init_mlx_window(t_game *game);
void			close_window(void *param);
void			key_hook(mlx_key_data_t keydata, void *param);
void			do_raycasting(t_game *game);
void			execute_dda_algorithm(t_game *game, t_ray *ray);
void			calculate_wall_height(t_game *game, t_ray *ray, int x);
void			draw_wall_line(t_game *game, t_ray *ray, int x);
mlx_texture_t	*set_orientation_texture(t_ray *ray, t_game *game);
uint32_t		draw_rgba_pixel(mlx_texture_t *tex, t_ray *ray, int tex_y);
void			calculate_tex_coords(t_ray *ray, t_game *game,
					mlx_texture_t *tex, double *step);
void			put_pixels_ceiling(t_game *game, t_ray *ray, int *y, int x);
void			put_pixels_floor(t_game *game, t_ray *ray, int *y, int x);
void			calculate_ceil_px_minimap(t_game *game, t_minimap *minimap);
void			fill_pixels(t_game *game, t_minimap *minimap);
void			create_minimap(t_game *game);

#endif