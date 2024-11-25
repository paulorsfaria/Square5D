/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:10:54 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/25 09:27:18 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	check_extension(char *file_name, char *ext, int len)
{
	if (len < 4)
		return (-1);
	if (ft_strncmp(file_name, ext, 5) == 0)
		return (-1);
	while (len > 0 && file_name[len]!= '.')
		len--;
	if (ft_strncmp(&file_name[len], ext, 5))
		return (ft_printf("invalid name\n"));
	return (0);
}

int	check_colors(char *line)
{
	int	comma;
	int	i;

	i = 0;
	comma = 0;
	printf("%s\n", line);
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ',')
		{
			comma++;
			i++;
		}
		if (line[i] != '\n' && ft_isdigit(line[i]) == 0 && line[i] != ',' && line[i] != ' ')
			return (-1);
		if (line[i] != '\0' && line[i] != '\n')
			i++;
	}
	if (comma != 2)
		return (-1);
	return (1);
}

int ft_check_map_limits(char *file_name)
{
	t_area	area;
	int fd;
	char *line;

	area.row = 0;
	area.column = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && line[0] != '1')
	{
		if (line[0] == 'F' || line[0] == 'C')
			if(check_colors(line) == -1)
				return (free(line), get_next_line(-1),printf("you fucked up the colors\n"), -1);
		free(line);
		line = get_next_line(fd);
	}
	//#TODO fix valgrinds leaks on get next line
	while (line != NULL)
	{
		if (area.row < ft_strlen(line))
			area.row = ft_strlen(line);
		area.column++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	printf("len: %d, hight: %d\n", area.row, area.column);
	close(fd);
	return (1);
}
int	ft_check_file_name(char *file_name)
{
	int	fd;
	int	len;

	fd = 0;
	len = ft_strlen(file_name);
	if(check_extension(file_name, ".cub", len) == -1)
		return (ft_printf("bad name\n"));
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (printf("Cant open this file\n"));
	close(fd);
	return 0;
}
int	main(int argc, char *argv[])
{
	/*
	 	* must limit max map btw memory isn't free now is it?
	 */
	argc--;
	if(argc == 1)
	{
		ft_check_file_name(argv[1]);
		ft_check_map_limits(argv[1]);

	}
	else if (argc > 1)
		ft_printf("Only one input is acepted");
	else
		ft_printf("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");

	return (0);
}