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

#include "../../headers/cub3d.h"

void	error_central_extra(int error_code)
{
	if (error_code == -8)
		ft_printf_err("Missing newline\n");
	if (error_code == -9)
		ft_printf_err("Missing textures\n");
	if (error_code == -10)
		ft_printf_err("Invalid texture\n");
	if (error_code == -11)
		ft_printf_err("Error in colors or assets\n");
	if (error_code == -12)
		ft_printf_err("Error with the player\n");
	if (error_code == -13)
		ft_printf_err("Error with the map\n");
	if (error_code == -14)
		ft_printf_err("Open map\n");
	if (error_code == -15)
		ft_printf_err("Error in ft_calloc\n");
	if (error_code == -16)
		ft_printf_err("Invalid ext.\n");
	if (error_code == -17)
		ft_printf_err("Error in textures\n");
}

int	error_central(int error_code, t_temp_map *map)
{
	if (map)
		free_map_parse(&map);
	ft_printf_err("Error\n");
	if (error_code == -1)
		ft_printf_err("Invalid file\n");
	if (error_code == -2)
		ft_printf_err("Cant open this file\n");
	if (error_code == -3)
		ft_printf_err("To many colors\n");
	if (error_code == -4)
		ft_printf_err("Error in colors\n");
	if (error_code == -5)
		ft_printf_err("Missing colors\n");
	if (error_code == -6)
		ft_printf_err("Colors must be from 0 to 255\n");
	if (error_code == -7)
		ft_printf_err("Invalid characters\n");
	if (error_code < -7)
		error_central_extra(error_code);
	exit(EXIT_FAILURE);
}
