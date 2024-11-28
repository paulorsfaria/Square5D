/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_extensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:30:14 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/28 16:30:14 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_check_file_name(char *file_name)
{
	int	fd;
	int	len;

	fd = 0;
	len = (int)ft_strlen(file_name);
	if (check_extension(file_name, ".cub", len) == -1)
		return (error_central(-1, NULL));
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (error_central(-2, NULL));
	close(fd);
	return (0);
}

int	check_extension(char *file_name, char *ext, int len)
{
	if (len < 4)
		return (-1);
	if (ft_strncmp(file_name, ext, 5) == 0)
		return (-1);
	while (len > 0 && file_name[len] != '.')
		len--;
	if (ft_strncmp(&file_name[len], ext, 5))
		return (error_central(-1, NULL));
	return (0);
}