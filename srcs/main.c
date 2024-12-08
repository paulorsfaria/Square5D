/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:45:00 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/08 15:27:00 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	first_check(t_temp_map *map, int i, int j)
{
	char	*temp;

	while (map->lines[i] != NULL)
	{
		while (map->lines[i][j] == ' ')
			j++;
		if (j > 0)
			j--;
		if (map->lines[i][j] == ' ' && (map->lines[i][j + 1] != '\0'
		&& map->lines[i][j + 1] != '1' && map->lines[i][j + 1] != '0'))
		{
			temp = ft_remove_extra_spaces(map->lines[i], map);
			free(map->lines[i]);
			map->lines[i] = temp;
		}
		j = 0;
		while (map->lines[i][j] == ' ')
			j++;
		ft_invalid_start(map, map->lines[i][j], i);
		j = 0;
		i++;
	}
}

void	check_bool_final(t_temp_map *map)
{
	first_check(map, 0, 0);
	if (map->valid->so == false || map->valid->no == false
		|| map->valid->we == false || map->valid->ea == false)
		print_error("textures", map);
	if (map->valid->c == false || map->valid->f == false)
		print_error("colors", map);
}
void	ft_flood_test(t_temp_map *map, int start, int end)
{

	(void)map;
	(void)start;
	(void)end;


}
void	check_map(t_temp_map *map, int start, int end)
{
	int	i;
	int	j;
	int player;

	i = -1;
	j = 0;
	player = 0;

	while (map->lines[++i])
	{
		while (map->lines[i][j] != '\0' && map->lines[i][j] == ' ')
			j++;
		if(player > 1)
		{ printf("asd%d\n", player);error_central(-12, map); }
		if ((start == 0 && map->lines[i][j] == '1') || map->lines[i][j] == '0')
			start = i;
		else if (map->lines[i][j] == '1' || map->lines[i][j] == '0')
			end = i;
		while(map->lines[i][++j] != '\0')
			if(start != 0 && (map->lines[i][j] == 'N' || map->lines[i][j] == 'S'
				|| map->lines[i][j] == 'E' || map->lines[i][j] == 'W'))
				player++;
		j = 0;
	}
	if(player == 0) { printf("asd\n");error_central(-12, map); }
	printf("%s\n",map->lines[start]);
	printf("%s\n",map->lines[end]);
	ft_flood_test(map, start, end);
	printf("%d | %d\n", start, end);

}

static int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

char	*ft_remove_extra_spaces(char *str, t_temp_map *map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!line)
	{
		ft_printf_err("Error in calloc\n");
		error_central(0, map);
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		while (str[i] && !is_whitespace(str[i]))
			line[j++] = str[i++];
		while (is_whitespace(str[i]))
			i++;
		if (i > 0 && str[i] != '\0')
			line[j++] = ' ';
	}
	line[j] = '\0';
	return (line);
}

int	main(int argc, char *argv[])
{
	t_temp_map	*map;

	argc--;
	if (argc == 1)
	{
		ft_check_file_name(argv[1]);
		map = calloc(sizeof(t_temp_map), 1);
		map->size = ft_get_file_size(argv[1]);
		ft_get_map(&map, argv[1]);
		check_bool_final(map);
		col_val(map, 0);
		check_textures(map, 0, 0, NULL);
		check_map(map, 0, 0);
		free_map(&map);
	}
	else if (argc > 1)
		ft_printf_err("Only one input is accepted");
	else
		ft_printf_err("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");
	return (0);
}
