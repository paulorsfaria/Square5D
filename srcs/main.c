/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:10:54 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/23 18:01:26 by paulo-do         ###   ########.fr       */
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

int	ft_check_file_name(char *file_name)
{
	int	fd;
	int	len;

	fd = 0;
	len = ft_strlen(file_name);
	// i need to check if its .cub at the start;
				// if (len < 4 || (len == 4 && !ft_strncmp(file_name, ".cub", 5)))
				// 	return (ft_printf("my dude just .cub is not supported\n"));
	if(check_extension(file_name, ".cub", len) == -1)
		return (ft_printf("bad name\n"));
	// try to open it;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (printf("Cant open this file\n"));
	close(fd);
	return 0;
}
int	main(int argc, char *argv[])
{
	/*
	 * it needs to be 1 arg
	 * the file must be .cub
	 * but can just .cub be accepted?
	 * must limit max map btw memory isn't free now is it?
	 */
	argc--;
	if(argc == 1)
	{
		ft_check_file_name(argv[1]);


	}
	else if (argc > 1)
		ft_printf("Only one input is acepted");
	else
		ft_printf("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");

	return (0);
}