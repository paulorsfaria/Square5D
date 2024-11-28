/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:10:54 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/27 13:52:17 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
	 * must limit max map btw memory isn't free now is it?
 */

int	ft_get_file_size(char *file)
{
	int fd;
	int size;
	char *line;

	size = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (size);

}
char **ft_get_file(char *file_name, t_temp_map *map)
{
	char **file;
	int fd;
	int i;

	i = 0;
	map->size = ft_get_file_size(file_name);
	file = ft_calloc(map->size + 1, sizeof(char *));
	fd = open(file_name, O_RDONLY);
	while (i < map->size)
	{
		file[i] = get_next_line(fd);
		i++;
	}
	file[i] = NULL;
	close(fd);
	return (file);
}
int	main(int argc, char *argv[])
{
	t_temp_map *file;
	argc--;
	if (argc == 1)
	{
		ft_check_file_name(argv[1]);
		file = calloc(sizeof(t_temp_map), 1);
		file->lines = ft_get_file(argv[1], file);
		ft_check_map(file);

	}
	else if (argc > 1)
		ft_printf_err("Only one input is accepted");
	else
		ft_printf_err("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");
	return (0);
}


/*
 *
 * #TO-DO only read one time the map into a char **
 */