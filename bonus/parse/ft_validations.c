/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:34:33 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/16 15:34:36 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

void	check_bool_final(t_temp_map *map)
{
	first_check(map, 0, 0);
	if (map->valid->so == false || map->valid->no == false
		|| map->valid->we == false || map->valid->ea == false)
		print_error("textures", map);
	if (map->valid->c == false || map->valid->f == false)
		print_error("colors", map);
}

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	ft_validations(char *argv[])
{
	t_temp_map	*map;

	ft_check_file_name(argv[1]);
	map = ft_calloc(sizeof(t_temp_map), 1);
	map->player = ft_calloc(sizeof(t_player), 1);
	map->size = ft_get_file_size(argv[1]);
	ft_get_map(&map, argv[1]);
	check_bool_final(map);
	col_val(map, -1);
	check_textures(map, 0, 0, NULL);
	check_map(map, 0, 0, -1);
	free_map_parse(&map);
}
