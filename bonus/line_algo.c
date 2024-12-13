/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:20:34 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/03 16:26:37 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_vision_angle_mini(t_mlx *win, float x, float y)
{
	float	mini_end_x;
	float	mini_end_y;
	float	x_step;
	float	y_step;
	int		max;

	mini_end_x = x + 2 * win->player->player_delta_x;
	mini_end_y = y + 2 * win->player->player_delta_y;
	x_step = mini_end_x - x;
	y_step = mini_end_y - y;
	max = fmax(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - mini_end_x) ||
		(int)(y - mini_end_y))
	{
		my_pixel_put(&win->img, x, y, 0x0000ff);
		x += x_step;
		y += y_step;
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
