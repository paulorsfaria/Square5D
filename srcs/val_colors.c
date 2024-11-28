/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:20:29 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/28 14:59:13 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	check_colors_limits(char *line, t_temp_map *map)
{
	int		i;
	int		flag;
	char	**new;

	i = -1;
	flag = 0;
	line[1] = ',';
	new = ft_split(line, ',');
	if (ft_atoi(new[1]) > 255 || ft_atoi(new[2]) > 255 || ft_atoi(new[3]) > 255)
		flag = -1;
	if (ft_atoi(new[1]) < 0 || ft_atoi(new[2]) < 0 || ft_atoi(new[3]) < 0)
		flag = -1;
	while (++i < 5)
		free(new[i]);
	free(new);
	if (flag == -1)
		return (error_central(-6, map));
	return (1);
}

int	check_colors(char *line, t_temp_map *map)
{
	int	comma;
	int	i;

	i = 0;
	comma = 0;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ',' && ft_isdigit(line[i + 1]) != 0 && i++ > 0)
			comma++;
		if (line[i] != ',' && ft_isdigit(line[i]) == 0)
			return (-1);
		if (line[i] != '\n' && ft_isdigit(line[i]) == 0
			&& line[i] != ',' && line[i] != ' ')
			return (-1);
		if (line[i] != '\0' && line[i] != '\n')
			i++;
	}
	if ((line[i] != '\0' && line[i] != '\n') || comma != 2)
		return (error_central(-4, map));
	check_colors_limits(line, map);
	return (1);
}
