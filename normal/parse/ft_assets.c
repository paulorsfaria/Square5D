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

void	line_checker(char **line, t_temp_map *map)
{
	if (!line[0] || !line[1])
	{
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

int	while_checker(t_temp_map *map, const int i, const int flag)
{
	if (flag == 1)
	{
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

	while (while_checker(map, i, 1) == 1)
		i++;
	while (while_checker(map, i, 0) == 1)
	{
		flag++;
		j = i;
		while (flag != 4 && (map->lines[j + 1][0] == '\0'))
			j++;
		if (while_checker(map, j + 1, 1) == 1)
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
