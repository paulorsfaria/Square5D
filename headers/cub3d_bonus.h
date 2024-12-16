/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:56:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/03 16:26:46 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

# define PI 3.14159265359
# define P2 1.57079632679 // PI/2
# define P3 4.71238898038 //3*PI/2

# define FOV 1.04719755 //(PI / 3)

# define TEXTURE_H 64
# define TEXTURE_Y 64

# define WIDTH 1920
# define HEIGHT 1080

# define SQUARE 64
# define SQUARE_MINI 16
# define PLAYER_SIZE 20
# define PLAYER_SIZE_MINI 10
# define OBSTACLE_COLOR 0x000000

# define DR 0.000545415 //(FOV / WIDTH)

typedef struct s_valid_map
{
	bool	so;
	bool	no;
	bool	we;
	bool	ea;
	bool	c;
	bool	f;
	bool	player;
}			t_valid_map;

typedef struct s_player_p
{
	int		f_y;
	int		f_x;
	int		y;
	int		x;
	char	player;
}		t_player_p;

typedef struct s_temp_map
{
	char		**lines;
	int			size;
	int			start;
	t_valid_map *valid;
	t_player_p	*player;
}			t_temp_map;

typedef enum e_exit
{
	FAILURE,
	SUCCESS,
}	t_exit;

//--------- calculations -------

typedef struct s_horizontal_intersection
{
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	atan;
}	t_h_inter;

typedef struct s_vertical_intersection
{
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	ntan;
}	t_v_inter;

typedef struct s_ray_vars
{
	int		r;
	float	ra;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	ray_h;
	float	ray_v;
	float	wall_x;
	float	line;
	float	line_h;
	float	line_v;
}	t_ray_vars;
//--------- ------------ -------

//--------- texture calculations -------

typedef struct s_texture_vars
{
	int		y;
	float	ty;
	float	tx;
	float	ty_step;
	float	ty_offset;
}	t_texture_vars;

//----------------------------

typedef struct s_map
{
	int					width;
	int					height;
	char				**coord;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	player_delta_x;
	float	player_delta_y;
	float	player_angle;
}	t_player;

typedef struct s_tex
{
	void	*mlx_img;
	char	*path;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_mlx
{
	void		*mlx_connect;
	void		*mlx_win;
	t_player	*player;
	t_map		*map;
	t_img		img;
	t_tex		north_texture;
	t_tex		east_texture;
	t_tex		south_texture;
	t_tex		west_texture;
	int			color_top;
	int			color_bot;
	int			texture_nbr;
}	t_mlx;



void	ft_vision_angle(t_mlx *win, float px, float py);

// --------------- img_create.c ------------------ //

void	my_pixel_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
void	render_background_top_bot(t_mlx *win, t_img *img);
int		get_pixel_color(t_tex *img, int x, int y);

// --------------- events.c --------------------- //

int		arrow_keys(int Key, t_mlx *mlx);

// --------------- draw_shapes.c ---------------- //

void	ft_update_player(float px, float py, t_img *img, t_mlx *win);
void	ft_draw_map(t_map *map, t_img *img, t_mlx *win);
void	draw_square(t_img *img, int x, int y, int color);
void	ft_draw_mini_map(t_map *map, t_img *img, int x, int y);

// --------------- utils.c --------------------- //

int		ft_mod(int n);
void	set_up_win(t_mlx *win, t_temp_map *map);
float	line_length(float x1, float y1, float x2, float y2);
int		ft_circle_normalizer(float *ra);
void	ft_value_setter(float *val1, float *set1, float *val2, float *set2);

// --------------- raycast.c --------------------- //

void	raycaster(t_mlx *win);
void	get_horizontal_intersection(t_mlx *win, float ra, float *hx, float *hy);
void	get_vertical_intersection(t_mlx *win, float ra, float *vx, float *vy);

// --------------- wall_and_textures.c --------------------- //

void	ft_texture_picker(t_mlx *win, float ray_point, char c);
void	draw_3d_walls(t_mlx *win, float distance, int column, float hx);

// --------------- line_algo.c  --------------------- //

void	ft_bresenhams_alg(t_mlx *win, float end_x, float end_y, int color);
void	ft_vision_angle_mini(t_mlx *win, float px, float py);

// --------------- clean_rotine.c --------------------- //

void	ft_cleanup_and_exit(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_event_checker(int Key, t_mlx *mlx);

// --------------- utils2.c --------------------- //

void	ft_rotate_right(t_mlx *mlx);
void	ft_rotate_left(t_mlx *mlx);
void	ft_init_vars(t_ray_vars	*vars, t_mlx *win);
char	ft_is_wall(float next_x, float next_y, char **map);


//ft_getters
int		ft_get_file_size(char *file);

//val_exts
int		ft_check_file_name(char *file_name);

//ft_error
int		error_central(int error_code, t_temp_map *map);
void	print_error(char *str, t_temp_map *map);

//ft_getters
void	ft_get_map(t_temp_map **map, char *file);
int	ft_get_start_map(t_temp_map *map);

//freedom city
void	free_map_parse(t_temp_map **map);
void	free_split(char **str);

//color validations
int		col_val(t_temp_map *map, int i);
int 	ft_invalid_start(t_temp_map *map, char c, int i);
int		check_extension(char *file_name, char *ext, int len);

//val_colo_utils
void	check_next_char(t_temp_map *map,int c, int i);


//ft_assets
void	check_textures(t_temp_map *map, int i, int j, char **temp);

char	*ft_remove_extra_spaces(char *str, t_temp_map *map);

//val_maps
void	check_map(t_temp_map *map, int start, int end, int i);

//flood
void	flood(t_temp_map *map, int y, int x, int map_size);
int		ft_check_first_last(char **map, int i);
int		check_the_sides(char **map, int y, int map_size);
void	ft_do_flood(t_temp_map *map, int start, int end, int i);

//ft_checkers
void	first_check(t_temp_map *map, int i, int j);

//ft_validations
void	ft_validations(char *argv[]);
int	is_whitespace(char c);
#endif