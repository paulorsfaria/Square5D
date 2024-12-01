/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:45:00 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/29 13:45:00 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void first_check(t_temp_map *map)
{
	int	i;

	i = 0;
	while (map->lines[i] != NULL)
	{
		ft_invalid_start(map, map->lines[i][0], i);
		i++;
	}
}

void print_error(char *str, t_temp_map *map)
{
	ft_printf_err("Missing %s\n", str);
	error_central(0, map);
}

void	check_bool_final(t_temp_map *map)
{
	first_check(map);
	if (map->valid->so == false || map->valid->no == false
		|| map->valid->we == false || map->valid->ea == false)
		print_error("textures", map);
	if (map->valid->c == false || map->valid->f == false)
		print_error("colors", map);
}

void	check_textures(t_temp_map *map)
{
	int i;
	char **temp;


	i = 0;
	while(map->lines[i] != 0)
	{
		while(map->lines[i][0] != 'S' && map->lines[i][0] != 'N'
			&& map->lines[i][0] != 'W' && map->lines[i][0] != 'E')
			i++;
		if (map->lines[i + 1][0] != 'S' && map->lines[i][0] != 'N'
			&& map->lines[i + 1][0] != 'W' && map->lines[i + 1][0] != 'E')
			error_central(-2, map);
		temp = ft_split(map->lines[i], ' ');
		check_extension(temp[1], ".cub", ft_strlen(temp[1]));
		
	}

}

int	main(int argc, char *argv[])
{
	t_temp_map	*map;

	argc--;
	if (argc == 1)
	{
		ft_check_file_name(argv[1]);
		map = calloc(sizeof(t_temp_map), 1);
		map->size = ft_get_file_size(argv[1]);
		ft_get_map(&map, argv[1]);
		check_bool_final(map);
		col_val(map, 0);
		check_textures(map);
		free_map(&map);
	}
	else if (argc > 1)
		ft_printf_err("Only one input is accepted");
	else
		ft_printf_err("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");
	return (0);
}
