/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:49:43 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/01 12:15:53 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_get_file_size(char *file)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd < -1)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size + 1);
}

void	ft_get_map(t_temp_map **map, char *file)
{
	int	fd;
	int	i;
	int	j;

	fd = 0;
	i = 0;
	j = 0;
	(*map)->lines = ft_calloc(sizeof(char *), (*map)->size + 1);
	(*map)->valid = ft_calloc(sizeof(t_valid_map), 1);
	fd = open (file, O_RDONLY);
	if (fd < 0)
		error_central(-1, (*map));
	(*map)->lines[i] = get_next_line(fd);
	while ((*map)->lines[i] != NULL)
	{
		while ((*map)->lines[i][j] != '\0' && (*map)->lines[i][j] != '\n')
			j++;
		(*map)->lines[i][j] = '\0';
		j = 0;
		i++;
		(*map)->lines[i] = get_next_line(fd);
	}
	(*map)->lines[i + 1] = NULL;
	(*map)->size = i;
	close(fd);
}

int	ft_get_start_map(t_temp_map *map)
{
	int	i;

	i = 0;
	while (map->lines[i][0] != ' ' && map->lines[i][0] != '1'
			&& map->lines[i][0] != '0')
		i++;
	return (i);
}
