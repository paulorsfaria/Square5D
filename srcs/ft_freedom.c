/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:31:29 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/27 16:32:45 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void ft_finish_get(int fd)
{
	char *line;

	line = get_next_line(fd);
	while (line != NULL )
	{
		free(line);
		line = get_next_line(fd);
	}
}