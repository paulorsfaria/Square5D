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

void	first_check(t_temp_map *map)
{
	int	i;
	int	j;
	char *temp;

	i = 0;
	j = 0;
	while (map->lines[i] != NULL)
	{
		while (map->lines[i][j] == ' ')
			j++;
		if (j > 0)
			j--;
		if (map->lines[i][j] == ' ' && (map->lines[i][j + 1] != '\0'
		&& map->lines[i][j + 1] != '1' && map->lines[i][j + 1] != '0'))
        {
            temp = ft_strtrim(map->lines[i], " ");
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

void	check_bool_final(t_temp_map *map)
{
	first_check(map);
	if (map->valid->so == false || map->valid->no == false
		|| map->valid->we == false || map->valid->ea == false)
		print_error("textures", map);
	if (map->valid->c == false || map->valid->f == false)
		print_error("colors", map);
}
void check_map(t_temp_map *map)
{
    int i = -1;
    int j = 0;

    while (map->lines[++i])
    {
        while(map->lines[i][j] != '\0' && map->lines[i][j] == ' ')
            j++;
        if (map->lines[i][j] == '1' || map->lines[i][j] == '0' )
            printf("%s\n", map->lines[i]);
        j=0;
    }
    j++;

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
		check_map(map);
		free_map(&map);
	}
	else if (argc > 1)
		ft_printf_err("Only one input is accepted");
	else
		ft_printf_err("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");
	return (0);
}
