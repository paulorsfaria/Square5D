/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:47:44 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/14 16:38:32 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_mod(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

float	line_length(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

/*
	this places the angle on the right position (value) 
	of ra on the trignometric circle
	if ra = -180{ (-180) + 2PI } ra = 180
	if ra = 390{ 390 - 2PI } ra = 30
*/
int	ft_circle_normalizer(float *ra)
{
	if (*ra < 0)
		*ra += 2 * PI;
	if (*ra > 2 * PI)
		*ra -= 2 * PI;
	return (SUCCESS);
}

char **get_final_map(t_temp_map *map)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = NULL;
	first_check(map, 0, 0);
	while (map->lines && map->lines[i][j] != '0' && map->lines[i][j] != '1' && map->lines[i][j] != ' ')
		i++;
	new_map = ft_calloc(sizeof(char *), (map->size - i) + 1);
	while (map->lines[i] != NULL)
	{
		new_map[j] = ft_strdup(map->lines[i]);
		i++;
		j++;
	}
	new_map[j] = NULL;
	return (new_map);
}

int get_map_size(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char *get_texture_path(t_temp_map *map, int c)
{
	int i;
	char **temp;
	char *path;
	path = NULL;

	i = 0;
	while (map->lines[i] && map->lines[i][0] != c)
		i++;
	if (map->lines[i][0] == c)
	{
		temp = ft_split(map->lines[i], ' ');
		path = ft_strdup(temp[1]);
		free_split(temp);
	}
	return (path);
}

int	get_max_len(char **map)
{
	int i;
	int max_len;

	i = 0;
	max_len = -1;
	while (map[i] != NULL)
	{
		if ((int)ft_strlen(map[i]) > max_len)
			max_len = (int)ft_strlen(map[i]);
		i++;
	}
	return (max_len + 1);
}
int rgb_to_int(int red, int green, int blue)
{
	if (red < 0)
		red = 0;
	if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

int	ft_get_colors(t_temp_map *map, int c)
{
	int		i;
	int		hex_color = 0;
	char	**temp;
	char	*color;

	i = 0;
	temp = NULL;
	while (map->lines[i] && map->lines[i][0] != c)
		i++;
	if (map->lines[i] && map->lines[i][0] == c)
	{
		temp = ft_split(map->lines[i], ' ');
		color = ft_strdup(temp[1]);
		free_split(temp);
		temp =  ft_split(color, ',');
		hex_color = rgb_to_int(ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
		free_split(temp);
		free(color);
	}
	return (hex_color);
}
float	ft_set_player(t_mlx *win, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i] != NULL)
	{
		while (map[i][j] != '\0' && map[i][j] != 'S'
		&& map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'E')
			j++;
		if (map[i][j] != '\0')
			break;
		j = 0;
	}
	win->player->x = (float)i;
	win->player->y = (float)j;
	if (map[i][j] == 'S')
		return(4.712389);
	if (map[i][j] == 'N')
		return(1.570796);
	if (map[i][j] == 'E')
		return(3.141593);
	return(0);
}
void	set_up_win(t_mlx *win, t_temp_map *map)
{
	win->mlx_connect = 0;
	win->mlx_win = 0;
	win->map = 0;
	win->texture_nbr = 0;
	win->map = ft_calloc(sizeof(t_map), 1);
	win->map->coord = get_final_map(map);
	win->color_top = ft_get_colors(map, 'F');
	win->color_bot = ft_get_colors(map, 'C');
	win->player = ft_calloc(sizeof(t_player), 1);
	win->north_texture.path = get_texture_path(map, 'N');
	win->south_texture.path = get_texture_path(map, 'S');
	win->west_texture.path = get_texture_path(map, 'W');
	win->east_texture.path = get_texture_path(map, 'E');
	win->map->height = get_map_size(win->map->coord) - 1;
	win->map->width = get_max_len(win->map->coord);
	win->player->player_angle = ft_set_player(win, win->map->coord);
	win->player->player_delta_x = cos(win->player->player_angle) * 7;
	win->player->player_delta_y = sin(win->player->player_angle) * 7;
}

void	ft_value_setter(float *val1, float *set1, float *val2, float *set2)
{
	*val1 = *set1;
	*val2 = *set2;
}
