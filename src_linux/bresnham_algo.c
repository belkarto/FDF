/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresnham_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:07:46 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/19 17:49:25 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linux_fdf.h"
#include <math.h>

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
	increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;
	new[0] = (R(startcolor)) + round(pix * increment[0]);
	new[1] = (G(startcolor)) + round(pix * increment[1]);
	new[2] = (B(startcolor)) + round(pix * increment[2]);
	newcolor = RGB(new[0], new[1], new[2]);
	return (newcolor);
}

void	plotpix_in_x(t_bres bres, int pk, t_img *img)
{
	int	i;

	i = -1;
	while (++i <= bres.dx)
	{
		bres.color = gradient(bres.color1, bres.color2, bres.dx, i);
		if (bres.x1 < bres.x2)
			bres.x1++;
		else
			bres.x1--;
		if (pk < 0)
		{
			my_mlx_pixel_put(img, bres.x1, bres.y1, bres.color);
			pk = pk + 2 * bres.dy;
		}
		else
		{
			if (bres.y1 < bres.y2)
				bres.y1++;
			else
				bres.y1--;
			my_mlx_pixel_put(img, bres.x1, bres.y1, bres.color);
			pk = pk + 2 * bres.dy - 2 * bres.dx;
		}
	}
}

void	plotpix_in_y(t_bres bres, int pk, t_img *img)
{
	int	i;

	i = -1;
	while (++i <= bres.dy)
	{
		bres.color = gradient(bres.color1, bres.color2, bres.dy, i);
		if (bres.y1 < bres.y2)
			bres.y1++;
		else
			bres.y1--;
		if (pk < 0)
		{
			my_mlx_pixel_put(img, bres.x1, bres.y1, bres.color);
			pk = pk + 2 * bres.dx;
		}
		else
		{
			if (bres.x1 < bres.x2)
				bres.x1++;
			else
				bres.x1--;
			my_mlx_pixel_put(img, bres.x1, bres.y1, bres.color);
			pk = pk + 2 * bres.dx - 2 * bres.dy;
		}
	}
}

void	plotpixel(t_bres bres, t_img *img)
{
	int	pk;

	pk = 2 * bres.dy - bres.dx;
	if (bres.dx > bres.dy)
		plotpix_in_x(bres, pk, img);
	else
		plotpix_in_y(bres, pk, img);
}

void	put_line(t_point p1, t_point p2, t_img *img)
{
	t_bres	br;

	br.x1 = p1.p_x;
	br.x2 = p2.p_x;
	br.y1 = p1.p_y;
	br.y2 = p2.p_y;
	br.dx = abs(br.x2 - br.x1);
	br.dy = abs(br.y2 - br.y1);
	br.color1 = p1.p_color;
	br.color2 = p2.p_color;
	plotpixel(br, img);
}
