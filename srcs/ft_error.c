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

int	error_central_extra(int error_code)
{
	if (error_code == -8)
		ft_printf_err("Missing newline\n");
	if (error_code == -9)
		ft_printf_err("Missing textures\n");
	if (error_code == -10)
		ft_printf_err("invalid texture\n");
	if (error_code == -11)
		ft_printf_err("Error in colors or assets\n");
	if (error_code == -12)
		ft_printf_err("Error with the player\n");
	if (error_code == -13)
		ft_printf_err("Error with the map\n");
}

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
		ft_printf_err("Error in colors\n");
	if (error_code == -5)
		ft_printf_err("Missing colors\n");
	if (error_code == -6)
		ft_printf_err("colors must be from 0 to 255\n");
	if (error_code == -7)
		ft_printf_err("invalid characters\n");
	if (error_code < -7)
		error_central_extra(error_code);
	ft_printf("Thank you for using our print a square services\n");
	exit(EXIT_FAILURE);
}

void	print_error(char *str, t_temp_map *map)
{
	ft_printf_err("Missing %s\n", str);
	error_central(0, map);
}
