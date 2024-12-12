#include "flood.h"
#include "../headers/cub3d.h"



t_player_f *get_player(char **map)
{
	t_player_f *player = NULL;
	int y = 0;
	int x = 0;

	player = ft_calloc(sizeof(t_player_f), 1);
	while(map[y])
	{
		while(map[y][x] != '\0' && (map[y][x] == '1' ||map[y][x] == '0'))
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
	map = ft_calloc(sizeof (char *), 9);
	line = get_next_line(fd);
	while(line != NULL)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	 i = 0;
	 player = get_player(map);
	printf("player is at  %d | %d\n", player->y, player->x);
	 while(map[i])
	 {
	 	printf("%s", map[i]);
	 	i++;
	 }
	return (0);
}