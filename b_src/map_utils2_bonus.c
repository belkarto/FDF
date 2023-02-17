/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:11:45 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/02 15:34:57 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	color_picker(int h)
{
	if (h == 0)
		return (0xffffff);
	else if (h > 0)
		return (0xff0000 + h);
	else
		return (0x11f2fa - h);
}

int	get_color(const char *str, int h)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'x')
		i++;
	if (str[i] == 'x')
		i++;
	else
		return (color_picker(h));
	while (str[i] != '\0')
	{
		result *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'W';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - '7';
		i++;
	}
	return (result);
}
