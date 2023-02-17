/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:04:14 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/16 01:35:56 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"
#include <stdlib.h>
#include <unistd.h>

void	background(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			my_mlx_pixel_put(img, i, j, 0x212121);
		}
	}
}

/*
 function that moves the modele and put it in the middle of the window
 */

void	center_objec(t_point **pnt, int width, int high, int *highest)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = WIN_W / 2 - pnt[high / 2][width / 2].p_x;
	y = WIN_H / 2 - pnt[high / 2][width / 2].p_y;
	i = -1;
	*highest = 1;
	while (++i < high)
	{
		j = -1;
		while (++j < width)
		{
			if (*highest < pnt[i][j].h)
				*highest = pnt[i][j].h;
			pnt[i][j].p_x += x;
			pnt[i][j].p_y += y;
		}
	}
}

void	make_3d(t_fdf *fdf)
{
	int	i;
	int	j;
	int	h;

	if (fdf->h_step == 0)
		h = 1;
	else
		h = fdf->h_step / 3;
	i = -1;
	while (++i < fdf->map_high)
	{
		j = -1;
		while (++j < fdf->map_width)
			fdf->pnt[i][j].p_y -= fdf->pnt[i][j].h * h;
	}
}

/*
 draw the map to the image
 */

void	put_map(t_fdf fdf, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	background(img);
	make_3d(&fdf);
	while (++i < fdf.map_high)
	{
		j = -1;
		while (++j < fdf.map_width)
		{
			if (j + 1 < fdf.map_width)
				put_line(fdf.pnt[i][j], fdf.pnt[i][j + 1], &fdf.img);
			if (i + 1 < fdf.map_high)
				put_line(fdf.pnt[i][j], fdf.pnt[i + 1][j], &fdf.img);
		}
	}
}

void	draw_map(t_fdf fdf)
{
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_W, WIN_H, "FDF");
	fdf.img.img = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, \
			&fdf.img.line_length, &fdf.img.endian);
	projection(&fdf);
	center_objec(fdf.pnt, fdf.map_width, fdf.map_high, &fdf.max_h);
	fdf.h_step = (fdf.pnt[0][0].p_y / fdf.max_h) / 2;
	put_map(fdf, &fdf.img);
	mlx_key_hook(fdf.win_ptr, key_hook, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close2, &fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img, 0, 0);
	mlx_loop(fdf.mlx_ptr);
}
