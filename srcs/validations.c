/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:23:40 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/28 16:23:40 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_check_map(t_temp_map *map)
{
	t_area	area;
	bool	color[2];
	int i;

	i = 0;
	color[0] = false;
	color[1] = false;
	area.row = 0;
	area.column = 0;
	while (map->lines[i] != NULL && map->lines[i][0] != '1')
	{
		if (map->lines[i][0] == 'F' || map->lines[i][0] == 'C')
		{
			if (map->lines[i][1] != ' ')
				return (-1);
			if ((map->lines[i][0] == 'F' && color[0] == true) || (map->lines[i][0] == 'C'
						 && color[1] == true))
				return (free(map->lines[i]), error_central(-3, map));
			if (map->lines[i][0] == 'F')
				color[0] = true;
			if (map->lines[i][0] == 'C')
				color[1] = true;
			if (check_colors(map->lines[i], map) == -1)
				return (free(map->lines[i]), error_central(-4, map));
		}
		i++;
	}
	if (color[0] == false || color[1] == false)
		return (error_central(-5, map));
	while (map->lines[i] != NULL)
	{
		if (area.row < (int)ft_strlen(map->lines[i]))
			area.row = (int)ft_strlen(map->lines[i]);
		area.column++;
		i++;
	}
	printf("len: %d, hight: %d\n", area.row, area.column);
	return (1);
}
