/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:09:32 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/23 17:17:59 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

typedef struct s_color
{
	int	*f[3];
	int	*c[3];
}			t_color;

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

typedef struct s_temp_map
{
	char		**lines;
	int			size;
	t_valid_map *valid;
}			t_temp_map;

typedef struct s_area
{
	int	row;
	int	column;
}			t_area;

typedef struct s_validation
{
	bool	colors;
	bool	walls;
	bool	map;
}		t_validation;

//ft_getters
int		ft_get_file_size(char *file);

//val_exts
int		ft_check_file_name(char *file_name);

//ft_error
int		error_central(int error_code, t_temp_map *map);
void	print_error(char *str, t_temp_map *map);

//ft_getters
void	ft_get_map(t_temp_map **map, char *file);

//freedom city
void	free_map(t_temp_map **map);
void free_split(char **str);

//color validations
int		col_val(t_temp_map *map, int i);
int 	ft_invalid_start(t_temp_map *map, char c, int i);
int		check_extension(char *file_name, char *ext, int len);

//val_colo_utils
void	check_next_char(t_temp_map *map,int c, int i);


//ft_assets
void	check_textures(t_temp_map *map);

#endif
