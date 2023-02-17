/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:00 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/16 01:37:41 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

void	my_mlx_pixel_put(t_img *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = fdf->addr + (y * fdf->line_length + \
				x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	key_hook(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
		exit(0);
	return (0);
}

int	close2(int key, t_fdf *fdf)
{
	(void)key;
	(void)fdf;
	exit (0);
}

/*
 turn each point to make the isomitric projection
 */

void	iso(t_fdf *fdf)
{
	int	i;
	int	j;
	int	*x;
	int	*y;

	i = -1;
	while (++i < fdf->map_high)
	{
		j = -1;
		while (++j < fdf->map_width)
		{
			x = &fdf->pnt[i][j].p_x;
			y = &fdf->pnt[i][j].p_y;
			fdf->pnt[i][j].p_x = (*x - *y) * cos(1);
			fdf->pnt[i][j].p_y = (*x + *y) * sin(0.7);
		}
	}
}

void	projection(t_fdf *fdf)
{
	if (ft_strncmp(fdf->camera, "ISO", ft_strlen("ISO")) == 0)
		iso(fdf);
}
