/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:28:06 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/03 09:24:05 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

void	render_background(t_img *img, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(img, x++, y, color);
		}
		++y;
	}
}

void	render_background_top_bot(t_mlx *win, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			my_pixel_put(img, x++, y, win->color_top);
		++y;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_pixel_put(img, x++, y, win->color_bot);
		++y;
	}
}

int	get_pixel_color(t_tex *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (-1);
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)pixel);
}
