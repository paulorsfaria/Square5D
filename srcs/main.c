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
		col_val(map, 0);
		free_map(&map);
	}
	else if (argc > 1)
		ft_printf_err("Only one input is accepted");
	else
		ft_printf_err("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");
	return (0);
}
