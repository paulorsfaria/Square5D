/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:47:44 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/17 13:56:06 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_circle_normalizer(float *ra)
{
	if (*ra < 0)
		*ra += 2 * PI;
	if (*ra > 2 * PI)
		*ra -= 2 * PI;
	return (SUCCESS);
}

char	*ft_copy_line(char *map, int max_line)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	line = ft_calloc(sizeof(char), max_line + 1);
	while (map[i] != '\0' && map[i] != '\n')
	{
		line[i] = map[i];
		if (map[i] == ' ')
			line[i] = '0';
		i++;
	}
	while (i < max_line)
	{
		line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	rgb_to_int(int red, int green, int blue)
{
	if (red < 0)
		red = 0;
	if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

void	ft_value_setter(float *val1, float *set1, float *val2, float *set2)
{
	*val1 = *set1;
	*val2 = *set2;
}
