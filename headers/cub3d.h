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
#define CUB3D_H

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
	int *f[3];
	int	*c[3];
}			t_color;

typedef struct s_temp_map
{
	char  	**lines;
	int 	size;
}			t_temp_map;


typedef struct s_area
{
	int row;
	int	column;
}			t_area;

typedef struct s_wall_textures
{
	int	so;
	int	no;
	int	we;
	int	ea;
}			t_wall_textures;

typedef struct s_map
{
	t_color colors;
	t_wall_textures textures;
}			t_map;

typedef struct s_validation
{
	bool	colors;
	bool	walls;
	bool	map;
}		t_validation;

//validations
int	check_extension(char *file_name, char *ext, int len);
int	ft_check_map(t_temp_map *file);
int	ft_check_file_name(char *file_name);

//funcs colors
int	check_colors(char *line, t_temp_map *map);

// ft_freedom
void ft_finish_get(int fd);
void	free_temp_map(t_temp_map *map);

//error central
int	error_central(int error_code, t_temp_map *map);


#endif
