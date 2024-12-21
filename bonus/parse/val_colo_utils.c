/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_colo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:49:26 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/05 14:49:26 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	check_next_char(t_temp_map *map, int c, int i)
{
	if ((c == 'S' || c == 'N') && map->lines[i][1] != 'O')
		error_central(-7, map);
	if (c == 'W' && map->lines[i][1] != 'E')
		error_central(-7, map);
	if (c == 'E' && map->lines[i][1] != 'A')
		error_central(-7, map);
	if ((c == 'F' || c == 'C') && map->lines[i][1] != ' ')
		error_central(-7, map);
}

char	*ft_color_special(char *line, int j, int i, t_temp_map *map)
{
	char	*new_line;

	new_line = ft_calloc(sizeof(char), ft_strlen(line) + 2);
	if (!new_line)
		error_central(-15, map);
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && !is_whitespace(line[i]))
		{
			new_line[j] = line[i];
			if ((line[i] == 'F' || line[i] == 'C')
				&& is_whitespace(line[i + 1]))
				new_line[++j] = ' ';
			j++;
			i++;
		}
		while (line[i] != '\0' && !is_whitespace(line[i]))
			new_line[j++] = line[i++];
		while (is_whitespace(line[i]))
			i++;
	}
	new_line[j] = '\0';
	free(line);
	return (new_line);
}
