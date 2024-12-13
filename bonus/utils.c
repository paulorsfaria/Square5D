/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:47:44 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/03 09:26:13 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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

void	set_up_win(t_mlx *win, char **map)
{
	int	y;

	y = 0;
	win->color_top = 0xADD8E6;
	win->color_bot = 0xdddddd;
	win->mlx_connect = 0;
	win->mlx_win = 0;
	win->map = 0;
	win->texture_nbr = 0;
	win->map = malloc(sizeof(t_map));
	win->player = malloc(sizeof(t_player));
	win->map->height = 10;
	win->map->width = ft_strlen(map[0]);
	win->player->player_angle = 0;
	win->player->player_delta_x = cos(win->player->player_angle) * 7;
	win->player->player_delta_y = sin(win->player->player_angle) * 7;
	win->map->coord = ft_calloc(win->map->height, sizeof(char *));
	while (y < win->map->height)
	{
		win->map->coord[y] = ft_strdup(map[y]);
		y++;
	}
}

void	ft_value_setter(float *val1, float *set1, float *val2, float *set2)
{
	*val1 = *set1;
	*val2 = *set2;
}
