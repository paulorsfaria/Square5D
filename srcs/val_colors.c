/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:20:29 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/27 12:20:29 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
		if (line[i] == ',' && ft_isdigit(line[i + 1]) != 0 && i++ > 0)
			comma++;
		if (line[i] != ',' && ft_isdigit(line[i]) == 0)
			return -1;
		if (line[i] != '\n' && ft_isdigit(line[i]) == 0 && line[i] != ',' && line[i] != ' ')
			return (-1);
		if (line[i] != '\0' && line[i] != '\n')
			i++;
	}
	if (comma != 2)
		return (-1);
	if (line[i] != '\0' && line[i]!= '\n')
		return (-1);
	return (1);
}
