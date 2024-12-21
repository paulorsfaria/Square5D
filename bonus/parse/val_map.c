/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:04:56 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/21 13:41:32 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	player_check(char c, int flag)
{
	if (flag == 1 && (c != 'N' && c != 'S' && c != 'E' && c != 'W'))
		return (-1);
	if (flag == 0 && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (1);
	return (0);
}

int	ft_check_line(int pos, t_temp_map *map)
{
	int			i;
	static int	flag = 0;

	i = 0;
	while (map->lines[pos][i] != '\0' && (map->lines[pos][i] == '1'
		|| map->lines[pos][i] == '0' || map->lines[pos][i] == ' '))
		i++;
	if (map->lines[pos][i] != '\0' && map->lines[pos][i] != '1'
		&& map->lines[pos][i] != '0' && map->lines[pos][i] != ' ')
		if (player_check(map->lines[pos][i], 1) == -1)
			flag = 4;
	i = 0;
	while (map->lines[pos][i] != '\0' && map->lines[pos][i] != '1'
		&& map->lines[pos][i] != '0')
		i++;
	if (map->lines[pos][i] == '\0')
		flag = 1;
	if (flag == 1 && (map->lines[pos][i] == '1' || map->lines[pos][i] == '0'))
		flag = 3;
	if (flag > 1)
		error_central(-13, map);
	return (0);
}

void	set_player(t_temp_map *map, int i, int start, int j)
{
	map->player->f_y = i;
	map->player->f_x = j;
	map->player->y = i - start;
	map->player->x = j;
	map->player->player = map->lines[map->player->y + start][map->player->x];
}

int	set_j(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	return (j);
}

void	check_map(t_temp_map *map, int start, int end, int i)
{
	int	j;
	int	player_cnt;

	player_cnt = 0;
	while (map->lines[++i])
	{
		j = set_j(map->lines[i]);
		if (start == 0 && (map->lines[i][j] == '1' || map->lines[i][j] == '0'))
			start = i;
		else if (map->lines[i][j] == '1' || map->lines[i][j] == '0')
			end = i;
		if (start != 0)
			ft_check_line(i, map);
		while (map->lines[i][++j] != '\0')
			if (start != 0 && (player_check(map->lines[i][j], 0) == 1)
				&& player_cnt++ > -2)
				set_player(map, i, start, j);
	}
	if (player_cnt != 1)
		error_central(-12, map);
	map->start = ft_get_start_map(map);
	if (map->lines[map->start - 1][0] != '\0')
		error_central(-8, map);
	ft_do_flood(map, start, end, i);
}
