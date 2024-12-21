/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:59:01 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/21 15:44:22 by paulo-do         ###   ########.fr       */
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
		{
			free_split(line);
			error_central(-10, map);
		}
		if (check_extension(line[1], ".xpm",
				ft_strlen(line[1])) == -1)
		{
			free_split(line);
			error_central(-16, map);
		}
	}
}

int	while_checker(t_temp_map *map, const int i, const int flag)
{
	if (flag == 1)
		if (map->lines[i] != NULL && map->lines[i][0] != 'S'
			&& map->lines[i][0] != 'N' && map->lines[i][0] != 'W'
			&& map->lines[i][0] != 'E')
			return (1);
	if (flag == 0)
		if (map->lines[i] != NULL && (map->lines[i][0] == 'S'
			|| map->lines[i][0] == 'N' || map->lines[i][0] == 'W'
			|| map->lines[i][0] == 'E'))
			return (1);
	return (0);
}

void	check_textures(t_temp_map *map, int i)
{
	int		flag;
	char	**temp;

	flag = 0;
	while (map->lines[i])
	{
		if (while_checker(map, i, 0) == 1)
			flag++;
		if (flag > 4)
			error_central(-17, map);
		if (while_checker(map, i, 0) == 1)
		{
			temp = ft_split(map->lines[i], ' ');
			if (!temp[0] || !temp[1] || temp[2])
				ft_free_pack(map, temp);
			line_checker(temp, map);
			free_split(temp);
		}
		i++;
		if (map->lines[i] && (map->lines[i][0] == '0'
			|| map->lines[i][0] == '1' || map->lines[i][0] == ' '))
			break ;
	}
}
