/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:51:37 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/29 13:52:19 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

#include "../headers/cub3d.h"

int	error_central(int error_code, t_temp_map *map)
{
	if (map)
		free_map(&map);
	if (error_code == -1)
		ft_printf_err("invalid file\n");
	if (error_code == -2)
		ft_printf_err("Cant open this file\n");
	if (error_code == -3)
		ft_printf_err("To many colors\n");
	if (error_code == -4)
		ft_printf_err("bad color\n");
	if (error_code == -5)
		ft_printf_err("Missing colors\n");
	if (error_code == -6)
		ft_printf_err("colors must be from 0 to 255\n");
	ft_printf("Thank you for using our print a square services\n");
	exit(EXIT_FAILURE);
}
