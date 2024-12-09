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

void	ft_flood_map(t_temp_map *map, int start, int end, t_player *player)
{
	(void)map;
	(void)start;
	(void)end;
	printf("the player is at %d | %d\n", player->y, player->x);

	/*
	 * first i need to go to the player pos and start from there make everything a
	 * something random
	 * 
	 */
}
//what to do ???
// give up?
//yes.

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

/*
 *I fucked up the part of the mal when there are white line in the middle wtf...
 *just give up
 *its easier
 * ignore that just create a function taht goes from the start to
 * the finish  vars and the make it run untill
 * map ont null to aee id there are nay more thinga in it
 */

void	set_player(t_player *player, int i, int start, int j)
{
	player->y = i - start;
	player->x = j;
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
		if ((start == 0 && map->lines[i][j] == '1') || map->lines[i][j] == '0')
			start = i;
		else if (map->lines[i][j] == '1' || map->lines[i][j] == '0')
			end = i;
		if (start != 0)
			ft_check_line(i, map);
		while (map->lines[i][++j] != '\0')
			if (start != 0 && (player_check(map->lines[i][j], 0) == 1)
				&& player_cnt++ > -2)
				set_player(map->player, i, start, j);
	}
	if (player_cnt != 1)
		error_central(-12, map);
	ft_flood_map(map, start, end, map->player);
}
