/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:22:51 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/30 16:22:51 by paulo-do         ###   ########.fr       */
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
	if (ft_atoi(new[1]) > 255 || ft_atoi(new[2]) > 255
		|| ft_atoi(new[3]) > 255)
		flag = -1;
	if (ft_atoi(new[1]) < 0 || ft_atoi(new[2]) < 0
		|| ft_atoi(new[3]) < 0)
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
		if (line[i] == ',' && i++ > 0)
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

bool	check_bools(bool val, t_temp_map *map)
{
	if (val == true)
		return (error_central(-11, map));
	return (true);
}

int	ft_invalid_start(t_temp_map *map, char c, int i)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E' || c == 'F'
		|| c == 'C' || c == '1' || c == '0'|| c == '\0')
		check_next_char(map, c, i);
	else
		error_central(-7, map);
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E'
		|| c == 'F' || c == 'C' || c == '1' || c == 0)
	{
		if (c == 'S' && map->lines[i][1] == 'O')
			map->valid->so = check_bools(map->valid->so, map);
		if (c == 'N' && map->lines[i][1] == 'O')
			map->valid->no = check_bools(map->valid->no, map);
		if (c == 'W' && map->lines[i][1] == 'E')
			map->valid->we = check_bools(map->valid->we, map);
		if (c == 'E' && map->lines[i][1] == 'A')
			map->valid->ea = check_bools(map->valid->ea, map);
		if (c == 'F' && map->lines[i][1] == ' ')
			map->valid->f = check_bools(map->valid->f, map);
		if (c == 'C' && map->lines[i][1] == ' ')
			map->valid->c = check_bools(map->valid->c, map);
	}
	return (1);
}

int	col_val(t_temp_map *map, int i)
{
	bool	color[2];

	color[0] = false;
	color[1] = false;
	while (map->lines[++i] != NULL && map->lines[i][0] != '1')
	{
		if (map->lines[i][0] == 'F')
			if ((i > 0 && map->lines[i - 1][0] != 'C' )
				&& map->lines[i + 1][0] != 'C' && map->lines[i + 1][0] != '\0')
				return (error_central(-4, map));
		if (map->lines[i][0] == 'C')
			if ((i > 0 && map->lines[i - 1][0] != 'F')
				&& (map->lines[i + 1][0] != 'F'
				&& map->lines[i + 1][0] != '\0'))
				return (error_central(-4, map));
		if (map->lines[i][0] == 'F' || map->lines[i][0] == 'C')
		{
			color[1 - (map->lines[i][0] - 67) / (70 - 67)] = true;
			if (check_colors(map->lines[i], map) == -1)
				return (error_central(-4, map));
		}
	}
	if (color[0] == false || color[1] == false)
		return (error_central(-5, map));
	return (1);
}
