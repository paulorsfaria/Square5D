/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:20:34 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/02 15:37:42 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_vision_angle(t_mlx *win, float px, float py)
{
	float	x_step;
	float	y_step;
	int		max;
	int		end_x;
	int		end_y;

	end_x = px + 5 * win->player->player_delta_x;
	end_y = py + 5 * win->player->player_delta_y;
	x_step = end_x - px;
	y_step = end_y - py;
	max = fmax(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(px - end_x) || (int)(py - end_y))
	{
		my_pixel_put(&win->img, px, py, 0xff00ff);
		px += x_step;
		py += y_step;
	}
}

void	ft_bresenhams_alg(t_mlx *win, float end_x, float end_y, int color)
{
	float	x_step;
	float	y_step;
	float	px;
	float	py;
	int		max;

	px = win->player->x;
	py = win->player->y;
	x_step = end_x - px;
	y_step = end_y - py;
	max = fmax(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(px - end_x) || (int)(py - end_y))
	{
		my_pixel_put(&win->img, px, py, color);
		px += x_step;
		py += y_step;
	}
}
