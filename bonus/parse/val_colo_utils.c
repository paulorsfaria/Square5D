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

#include "../../headers/cub3d_bonus.h"

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
