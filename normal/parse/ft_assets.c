/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:59:01 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/08 16:31:04 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	val_text(char **temp, t_temp_map *map)
{
	(void)temp;
	(void)map;
}

//	win->north_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
//				"./assets/north_texture.xpm", &win->north_texture.width,
//				&win->north_texture.height);
//		win->north_texture.addr = mlx_get_data_addr(win->north_texture.mlx_img,
//				&win->north_texture.bpp, &win->north_texture.line_len,
//				&win->north_texture.endian);

void	line_checker(char **line, t_temp_map *map)
{
	if (!line[0] || !line[1])
	{
		val_text(line, map);
		free_split(line);
		error_central(-9, map);
	}
	if (line[0] && line[1])
	{
		if (line[2])
			error_central(-10, map);
		if (check_extension(line[1], ".xpm",
				ft_strlen(line[1])) == -1)
		{
			free_split(line);
			ft_printf_err("invalid ext\n");
			error_central(0, map);
		}
	}
}

int	while_checker(t_temp_map *map, const int i, const int flag, int color)
{
//	int	j;

//	j = -1;
	if (flag == 1)
	{
		(void)color;
//		while (map->lines[i][++j] != '\0')
//		{
//			if (map->lines[i][j] == 'C' || map->lines[i][j] == 'F')
//				color = 1;
//			if (color == 0 && (map->lines[i][j] == '1'
//				|| map->lines[i][j] == '0'))
//				{
//					printf("%d | %d | %c | %s \n", i,j, map->lines[i][j], map->lines[i]);
//					print_error("textures", map);
//				}
//		}
		if (map->lines[i] != NULL && map->lines[i][0] != 'S'
			&& map->lines[i][0] != 'N' && map->lines[i][0] != 'W'
			&& map->lines[i][0] != 'E')
			return (1);
	}
	if (flag == 0)
		if (map->lines[i] != NULL && (map->lines[i][0] == 'S'
			|| map->lines[i][0] == 'N' || map->lines[i][0] == 'W'
			|| map->lines[i][0] == 'E'))
			return (1);
	return (0);
}

void	check_textures(t_temp_map *map, int i, int j, char **temp)
{
	static int	flag = 0;

	while (while_checker(map, i, 1, 0) == 1)
		i++;
	while (while_checker(map, i, 0, 0) == 1)
	{
		flag++;
		j = i;
		while (flag != 4 && (map->lines[j + 1][0] == '\0'))
			j++;
		if (while_checker(map, j + 1, 1, 0) == 1)
			if (flag < 3)
				error_central(-9, map);
		if (flag == 4 && map->lines[j + 1][0] != '\0')
			error_central(-8, map);
		temp = ft_split(map->lines[i], ' ');
		if (temp[0] && temp[1] && temp[1][0] != '.')
		{
			free_split(temp);
			error_central(-9, map);
		}
		line_checker(temp, map);
		free_split(temp);
		i = j + 1;
	}
}
