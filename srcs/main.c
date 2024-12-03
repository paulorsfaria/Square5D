/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:45:00 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/03 12:21:09 by paulo-do         ###   ########.fr       */
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
	int j;
	char **temp;
	static int flag = 0;

	i = 0;
	while(map->lines[i] != NULL && map->lines[i][0] != 'S' && map->lines[i][0] != 'N'
		  && map->lines[i][0] != 'W' && map->lines[i][0] != 'E')
		i++;
	while(map->lines[i] != NULL)
	{

		flag++;
		if (map->lines[i + 1] != NULL && map->lines[i + 1][0] != 'S' && map->lines[i][0] != 'N'
			&& map->lines[i + 1][0] != 'W' && map->lines[i + 1][0] != 'E')
		{
			if (flag < 3)
			{
				printf("SEG HERE?\n");
				error_central(-9, map);
			}

		}
		if (flag == 4 && map->lines[i + 1][0] != '\0')
			error_central(-8, map);
		temp = ft_split(map->lines[i], ' ');
		if (temp[0] && temp[1] && temp[1][0] == '.')
			error_central(-9, map);
		if (!temp[1])
		{	j = 0;
			while (temp[j] != NULL)
				free(temp[j++]);
			free(temp);
			error_central(-9, map);

		}
		if (temp[0] && temp[1])
		{
			if (check_extension(temp[1], ".xpm", ft_strlen(temp[1])) == -1) {

				j = 0;
				while (temp[j] != NULL)
					free(temp[j++]);
				free(temp);
				ft_printf_err("invalid ext\n");
				error_central(0, map);
			}
		}
		j = 0;
		while (temp[j] != NULL)
			free(temp[j++]);
		free(temp);
		i++;
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
