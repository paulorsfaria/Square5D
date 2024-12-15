/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:23:18 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/02 15:37:28 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"



void	ft_cleanup_and_exit(t_mlx *mlx)
{
	if (mlx->mlx_connect != NULL)
	{
		mlx_destroy_image(mlx->mlx_connect, mlx->img.mlx_img);
		if (mlx->north_texture.mlx_img)
		{
			mlx_destroy_image(mlx->mlx_connect, mlx->north_texture.mlx_img);
			free(mlx->north_texture.path);
		}
		if (mlx->south_texture.mlx_img)
		{
			mlx_destroy_image(mlx->mlx_connect, mlx->south_texture.mlx_img);
			free(mlx->south_texture.path);
		}
		if (mlx->east_texture.mlx_img)
		{
			mlx_destroy_image(mlx->mlx_connect, mlx->east_texture.mlx_img);
			free(mlx->east_texture.path);
		}
		if (mlx->west_texture.mlx_img)
		{
			mlx_destroy_image(mlx->mlx_connect, mlx->west_texture.mlx_img);
			free(mlx->west_texture.path);
		}
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx_connect, mlx->mlx_win);
		if (mlx->mlx_connect != NULL)
			mlx_destroy_display(mlx->mlx_connect);
		free(mlx->mlx_connect);
	}

	if (mlx->map != NULL)
	{
		free_split(mlx->map->coord);
		free(mlx->map);
	}
	if (mlx->player != NULL)
		free(mlx->player);
	free(mlx);
	exit(0);
}

int	ft_close(t_mlx *mlx)
{
	ft_cleanup_and_exit(mlx);
	return (0);
}

int	ft_event_checker(int Key, t_mlx *mlx)
{
	if (Key == XK_Escape)
		ft_cleanup_and_exit(mlx);
	return (0);
}
