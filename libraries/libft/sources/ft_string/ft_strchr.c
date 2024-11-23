/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <diteixei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:41:21 by paulo-do          #+#    #+#             */
/*   Updated: 2024/09/19 10:35:44 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while ((str[i] != (char)c) && str[i] != '\0')
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	else
		return (NULL);
}
