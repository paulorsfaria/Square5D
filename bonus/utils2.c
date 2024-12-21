/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:31:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/19 08:57:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	ft_rotate_left(t_mlx *mlx)
{
	mlx->player->player_angle -= 0.1;
	if (mlx->player->player_angle < 0)
		mlx->player->player_angle += 2 * PI;
	mlx->player->player_delta_x = cos(mlx->player->player_angle) * 7;
	mlx->player->player_delta_y = sin(mlx->player->player_angle) * 7;
}

void	ft_rotate_right(t_mlx *mlx)
{
	mlx->player->player_angle += 0.1;
	if (mlx->player->player_angle > 2 * PI)
		mlx->player->player_angle -= 2 * PI;
	mlx->player->player_delta_x = cos(mlx->player->player_angle) * 7;
	mlx->player->player_delta_y = sin(mlx->player->player_angle) * 7;
}

void	ft_init_vars(t_ray_vars	*vars, t_mlx *win)
{
	vars->r = -1;
	vars->ra = win->player->player_angle - (FOV / 2);
}

char	ft_is_wall(float next_x, float next_y, float player_size, t_mlx *mlx)
{
	t_coords	coords;
	int			y;
	int			x;

	coords.top_left_x = (next_x - player_size) / 64;
	coords.top_left_y = (next_y - player_size) / 64;
	coords.bottom_right_x = (next_x + player_size) / 64;
	coords.bottom_right_y = (next_y + player_size) / 64;
	y = coords.top_left_y;
	while (y <= coords.bottom_right_y)
	{
		x = coords.top_left_x;
		while (x <= coords.bottom_right_x)
		{
			if (y < 0 || y >= mlx->map->height || x < 0 || x >= mlx->map->width)
				return ('1');
			if (mlx->map->coord[y][x] == '1')
				return ('1');
			x++;
		}
		y++;
	}
	return ('0');
}

float	line_length(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
