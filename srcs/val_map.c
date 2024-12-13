/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:04:56 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/09 13:04:56 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
int		check_the_sides(char **map, int y, int map_size)
{
	int x = 0;

	while(y < map_size)
	{
		while(map[y][x] == ' ')
			x++;
		if (map[y][x] == 'F')
			return (-1);
		while(map[y][x] != '\0' &&  map[y][x] != '\n')
		{
			if (map[y][x] == 'F' && !map[y + 1][x])
				return -1;
			x++;
		}
		if (x > 0)
			x--;
		while(map[y][x] == ' ')
			x--;
		if (map[y][x] == 'F')
			return (-1);

		x = 0;
		y++;
	}
	return 1;
}
int		ft_check_first_last(char **map, int i)
{
	int j =0;
	while(map[i][j] != '\0')
	{
		if(map[i][j] == 'F')
			return -1;
		j++;
	}
	while(map[i])
		i++;
	i--;
	j = 0;
	while (map[i][j] != '\0')
	{
		if(map[i][j] == 'F')
			return -1;
		j++;
	}
	return 1;
}
void	flood(t_temp_map *map, int y, int x, int map_size)
{
	printf("start %d | y %d | x %d\n", map->start, y, x);
	if(y > map_size || y < map->start)
		return;
	if (x > (int)ft_strlen(map->lines[y]))
		return;
	if (map->lines[y][x] != '0' && map->lines[y][x] != ' ' && map->lines[y][x] != 'N')
		return;
	if (map->lines[y][x] == '0' || map->lines[y][x] == ' ')
		map->lines[y][x] = 'F';
	flood(map, y + 1, x, map_size);
	flood(map, y - 1, x, map_size);
	flood(map, y, x + 1, map_size);
	flood(map, y, x -1, map_size);
}


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

void	check_map(t_temp_map *map, int start, int end, int i)
{
	int	j;
	int	player_cnt;

	player_cnt = 0;
	while (map->lines[++i])
	{
		j = 0;
		while (map->lines[i][j] == ' ')
			j++;
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
	map->start = 0;
	while (map->lines[map->start][0] != ' '
	&& map->lines[map->start][0] != '1'
			&& map->lines[map->start][0] != '1')
		map->start++;
	flood(map, map->player->f_y, map->player->f_x, i);
	if (ft_check_first_last(map->lines, start) == -1
		|| check_the_sides(map->lines,map->start + 1, end) == -1)
		{
		printf("open map\n");
			exit(EXIT_FAILURE);
	}


}
