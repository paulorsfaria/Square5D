/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:17:00 by paulo-do          #+#    #+#             */
/*   Updated: 2024/11/30 16:00:32 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_map(t_temp_map **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i <= (*map)->size)
		{
			free((*map)->lines[i]);
			i++;
		}
		free((*map)->lines);
		free((*map)->valid);
		free((*map)->player);
		free(*map);
	}
}

void	free_split(char **str)
{
	int	j;

	j = 0;
	while (str[j] != NULL)
		free(str[j++]);
	free(str);
}
