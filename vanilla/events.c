/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:32:11 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/02 15:37:38 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	ft_go_up(t_mlx *mlx);
static void	ft_go_down(t_mlx *mlx);
static void	ft_go_left(t_mlx *mlx);
static void	ft_go_right(t_mlx *mlx);

int	arrow_keys(int Key, t_mlx *mlx)
{
	if (Key == XK_Left)
		ft_rotate_left(mlx);
	if (Key == XK_Right)
		ft_rotate_right(mlx);
	if (Key == XK_Up || Key == XK_w)
		ft_go_up(mlx);
	if (Key == XK_Down || Key == XK_s)
		ft_go_down(mlx);
	if (Key == XK_a)
		ft_go_left(mlx);
	if (Key == XK_d)
		ft_go_right(mlx);
	return (0);
}

static void	ft_go_up(t_mlx *mlx)
{
	mlx->player->x += mlx->player->player_delta_x;
	mlx->player->y += mlx->player->player_delta_y;
}

static void	ft_go_down(t_mlx *mlx)
{
	mlx->player->x -= mlx->player->player_delta_x;
	mlx->player->y -= mlx->player->player_delta_y;
}

static void	ft_go_left(t_mlx *mlx)
{
	mlx->player->x += mlx->player->player_delta_y * 0.63;
	mlx->player->y -= mlx->player->player_delta_x * 0.63;
}

static void	ft_go_right(t_mlx *mlx)
{
	mlx->player->x -= mlx->player->player_delta_y * 0.63;
	mlx->player->y += mlx->player->player_delta_x * 0.63;
}
