#include "flood.h"
#include "../headers/cub3d.h"

void	flood(char **map, int y, int x, int map_size)
{
	if(y > map_size || y < 0)
		return;
	if (x > ft_strlen(map[y]))
		return;
	if (map[y][x] != '0' && map[y][x] != ' ' && map[y][x] != 'N')
		return;
	if (map[y][x] == '0' || map[y][x] == ' ')
		map[y][x] = 'F';
	flood(map, y + 1, x, map_size);
	flood(map, y - 1, x, map_size);
	flood(map, y, x + 1, map_size);
	flood(map, y, x -1, map_size);
}


t_player_f *get_player(char **map)
{
	t_player_f *player = NULL;
	int y = 0;
	int x = 0;

	player = ft_calloc(sizeof(t_player_f), 1);
	while(map[y])
	{
		while(map[y][x] != '\0' && (map[y][x] == '1' || map[y][x] == ' ' ||map[y][x] == '0'))
				x++;
		if (map[y][x] != '\n' && map[y][x] != '\0')
		{
			player->y = y;
			player->x = x;
			return (player);
		}
		x = 0;
		y++;
	}
	return NULL;
}
int		check_the_sides(char **map, int map_size)
{
	int y = 1;
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
int		ft_check_first_last(char **map)
{
	int i = 0;
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
//
//	check all sides looking for an F
//
int main(int argc, char *argv[])
{
	char **map;
	int i = 0;
	int fd = 0;
	char *line;
	t_player_f *player = NULL;

	if(argc != 2)
		return 0;
	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(sizeof (char *), 25);
	line = get_next_line(fd);
	while(line != NULL)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	 player = get_player(map);
	printf("map_size id %d | player is at  %d | %d\n", i, player->y, player->x);
	flood(map, player->y, player->x, i - 1);
	if (ft_check_first_last(map) == -1 || check_the_sides(map, i) == -1)
		return (printf("open map\n"));
	i = 0;
	while(map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	return (0);
}