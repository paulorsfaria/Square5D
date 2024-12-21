/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:45:28 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/03 16:29:51 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

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

void	draw_mini_square(t_img *img, int x, int y, int color)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = x * SQUARE_MINI;
	start_y = y * SQUARE_MINI;
	i = 0;
	while (i < SQUARE_MINI)
	{
		j = 0;
		while (j < SQUARE_MINI)
		{
			if (i > 0 && j > 0)
				my_pixel_put(img, start_x + j, start_y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_mini_map(t_map *map, t_img *img, int x, int y)
{
	int			width;
	int			height;

	width = map->width * SQUARE_MINI;
	height = map->height * SQUARE_MINI;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			my_pixel_put(img, x, y, 0xAAAAAA);
	}
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width && map->coord[y][x] != '\0')
		{
			if (map->coord[y][x] == '1')
				draw_mini_square(img, x, y, 0x000000);
			else
				draw_mini_square(img, x, y, 0xFFFFFF);
		}
	}
}

void	ft_update_player(float px, float py, t_img *img, t_mlx *win)
{
	float	y;
	float	x;
	float	radius;
	int		circle_x;
	int		circle_y;

	(void)win;
	circle_x = px + SQUARE_MINI / 5;
	circle_y = py + SQUARE_MINI / 5;
	radius = PLAYER_SIZE_MINI / 2.0;
	y = 0;
	while (y < PLAYER_SIZE_MINI)
	{
		x = 0;
		while (x < PLAYER_SIZE_MINI)
		{
			if ((x - radius) * (x - radius) + (y - radius) * (y - radius)
				<= radius * radius)
				my_pixel_put(img, x + circle_x - radius,
					y + circle_y - radius, 0x0000FF);
			x++;
		}
		y++;
	}
	ft_vision_angle_mini(win, circle_x, circle_y);
}
