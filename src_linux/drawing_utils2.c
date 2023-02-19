/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:00 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/19 17:49:47 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/linux_fdf.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = fdf->addr + \
		(y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	iso(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < fdf->map_high)
	{
		j = -1;
		while (++j < fdf->map_width)
		{
			x = fdf->pnt[i][j].p_x * fdf->step;
			y = fdf->pnt[i][j].p_y * fdf->step;
			fdf->pnt_af[i][j].p_x = (x - y) * cos(fdf->x_axis);
			x = fdf->pnt_af[i][j].p_x;
			fdf->pnt_af[i][j].p_y = (x + y) * sin(fdf->y_axis);
			fdf->pnt_af[i][j].h = fdf->pnt[i][j].h * fdf->h_step;
			fdf->pnt_af[i][j].p_y -= fdf->pnt_af[i][j].h;
			fdf->pnt_af[i][j].p_color = fdf->pnt[i][j].p_color;
		}
	}
}

void	rotat(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < fdf->map_high)
	{
		j = -1;
		while (++j < fdf->map_width)
		{
			fdf->pnt_af[i][j].p_x = fdf->pnt[i][j].p_x * fdf->step;
			fdf->pnt_af[i][j].p_y = fdf->pnt[i][j].p_y * fdf->step;
			x = fdf->pnt_af[i][j].p_x;
			y = fdf->pnt_af[i][j].p_y;
			fdf->pnt_af[i][j].p_x = x * cos(fdf->x_axis) - y * sin(fdf->x_axis);
			fdf->pnt_af[i][j].p_y = y * cos(fdf->y_axis) + x * sin(fdf->y_axis);
			fdf->pnt_af[i][j].h = fdf->pnt[i][j].h * fdf->h_step;
			fdf->pnt_af[i][j].p_y -= fdf->pnt_af[i][j].h;
			fdf->pnt_af[i][j].p_color = fdf->pnt[i][j].p_color;
		}
	}
}

int	key_hook(int key, t_fdf *fdf)
{
	ft_printf("%d\n", key);
	if (key == ESC)
		exit(0);
	else if (key == K_I || key == K_P)
		iso_key(fdf, key);
	if (key == K_PLUS || key == K_MINUS)
		height_control(fdf, key);
	if (key == K_W || key == K_A || key == K_S || key == K_D
		|| key == K_Q || key == K_E)
		rotation_control(fdf, key);
	else if (key == K_F || key == 102)
	{
		fdf->camera = "ROTATE";
		fdf->x_axis = 0;
		fdf->y_axis = 0;
		rotat(fdf);
	}
	else if (key == K_R)
		reset(fdf);
	rerander(*fdf, &fdf->img);
	return (0);
}

int	close2(int key, t_fdf *fdf)
{
	(void)key;
	(void)fdf;
	exit (0);
}
