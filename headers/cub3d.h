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
# include "../libraries/libft/includes/libft.h"

typedef struct s_color
{
	int *f[3];
	int	*c[3];
}			t_color;


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

#endif
