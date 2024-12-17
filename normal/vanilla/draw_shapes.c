/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:45:28 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/02 15:37:36 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_square(t_img *img, int x, int y, int color)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = x * SQUARE;
	start_y = y * SQUARE;
	i = 0;
	while (i < SQUARE)
	{
		j = 0;
		while (j < SQUARE)
		{
			if (i > 0 && j > 0)
				my_pixel_put(img, start_x + j, start_y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_map *map, t_img *img, t_mlx *win)
{
	int			y;
	int			x;
	static int	v;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width && map->coord[y][x] != '\0')
		{
			if (map->coord[y][x] == '1')
				draw_square(img, x, y, 0x000000);
			else if (map->coord[y][x] == '0' || map->coord[y][x] == ' ')
				draw_square(img, x, y, 0xFFFFFF);
			else if (map->coord[y][x] == 'N' || map->coord[y][x] == 'W'
				|| map->coord[y][x] == 'S' || map->coord[y][x] == 'E' )
			{
				draw_square(img, x, y, 0xFFFFFF);
				if (v == 0)
				{
					win->player->x = x * SQUARE + PLAYER_SIZE;
					win->player->y = y * SQUARE + PLAYER_SIZE;
					v++;
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_update_player(int px, int py, t_img *img, t_mlx *win)
{
	float	y;
	float	x;
	int		size;

	(void)win;
	size = PLAYER_SIZE;
	y = 0;
	while (y < size && y + py < HEIGHT)
	{
		x = 0;
		while (x < size && x + px < WIDTH)
		{
			if (x > 0 && y > 0)
				my_pixel_put(img, x + px - PLAYER_SIZE / 2,
					y + py - PLAYER_SIZE / 2, 0x0000F0);
			x++;
		}
		y++;
	}
}
