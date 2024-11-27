/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_central.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:38:51 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/27 16:38:51 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	error_central(int error_code, int fd)
{
	if (fd > -1)
		ft_finish_get(fd);
	if (error_code == -1)
		printf("To many colors");
	if (error_code == -2)
		printf("To many colors");
}
