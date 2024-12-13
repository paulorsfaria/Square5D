/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:02 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/13 16:46:02 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	first_check(t_temp_map *map, int i, int j)
{
	char	*temp;

	while (map->lines[i] != NULL)
	{
		while (map->lines[i][j] == ' ')
			j++;
		if (j > 0)
			j--;
		if (map->lines[i][j] == ' ' && (map->lines[i][j + 1] != '\0'
			&& map->lines[i][j + 1] != '1' && map->lines[i][j + 1] != '0'))
		{
			temp = ft_remove_extra_spaces(map->lines[i], map);
			free(map->lines[i]);
			map->lines[i] = temp;
		}
		j = 0;
		while (map->lines[i][j] == ' ')
			j++;
		ft_invalid_start(map, map->lines[i][j], i);
		j = 0;
		i++;
	}
}
