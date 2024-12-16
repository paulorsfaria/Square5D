/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:31:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/03 11:46:17 by diogosan         ###   ########.fr       */
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

char	ft_is_wall(float next_x, float next_y, char **map)
{
	int	grid_x;
	int	grid_y;

	grid_x = next_x / 64;
	grid_y = next_y / 64;
	if (grid_y < 0 || grid_y >= HEIGHT || grid_x < 0 || grid_x >= WIDTH)
		return ('1');
	return (map[(int)grid_y][(int)grid_x]);
}
