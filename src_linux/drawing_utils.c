/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:04:14 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/19 17:52:03 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/linux_fdf.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_menu_win(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 425)
	{
		j = -1;
		while (++j < 375)
			my_mlx_pixel_put(img, j, i, 0x212121);
	}
}

void	center_objec(t_point **pnt, int width, int high, t_fdf fdf)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = WIN_W / 2 - pnt[high / 2][width / 2].p_x;
	y = WIN_H / 2 - pnt[high / 2][width / 2].p_y;
	i = -1;
	(void)fdf;
	while (++i < high)
	{
		j = -1;
		while (++j < width)
		{
			pnt[i][j].p_x += x + fdf.move_x;
			pnt[i][j].p_y += y + fdf.move_y;
		}
	}
}

void	rerander(t_fdf fdf, t_img *img)
{
	int	i;
	int	j;

	(void)img;
	fdf.img.img = mlx_new_image(fdf.mlx_ptr, WIN_W, WIN_H);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, \
			&fdf.img.line_length, &fdf.img.endian);
	i = -1;
	center_objec(fdf.pnt_af, fdf.map_width, fdf.map_high, fdf);
	while (++i < fdf.map_high)
	{
		j = -1;
		while (++j < fdf.map_width)
		{
			if (j + 1 < fdf.map_width)
				put_line(fdf.pnt_af[i][j], fdf.pnt_af[i][j + 1], &fdf.img);
			if (i + 1 < fdf.map_high)
				put_line(fdf.pnt_af[i][j], fdf.pnt_af[i + 1][j], &fdf.img);
		}
	}
	ft_menu_win(&fdf.img);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img, 0, 0);
	ft_menu(&fdf);
}

void	put_init(t_fdf *fdf)
{
	fdf->text = ft_strdup("PRESS   OR   OR   TO START");
	mlx_string_put(MLX_P, WIN_P, 100, 100, RED, fdf->text);
	free(fdf->text);
	fdf->text = ft_strdup("      I    P    F         ");
	mlx_string_put(MLX_P, WIN_P, 100, 100, YELLOW, fdf->text);
	free(fdf->text);
	fdf->text = ft_strdup("YOU CAN PRESS         OR     TO ROTATE");
	mlx_string_put(MLX_P, WIN_P, 100, 150, RED, fdf->text);
	free(fdf->text);
	fdf->text = ft_strdup("              A/W/S/D    Q/E          ");
	mlx_string_put(MLX_P, WIN_P, 100, 150, YELLOW, fdf->text);
	free(fdf->text);
	fdf->text = ft_strdup("YOU MOVE THE WIREFRAM MODELE USING          ");
	mlx_string_put(MLX_P, WIN_P, 100, 200, RED, fdf->text);
	free(fdf->text);
	fdf->text = ft_strdup("                                   THE MOUSE");
	mlx_string_put(MLX_P, WIN_P, 100, 200, YELLOW, fdf->text);
	free(fdf->text);
	fdf->text = ft_strdup("YOU CAN CONTROL THE WIREFRAM ALTITUDE USING    ");
	mlx_string_put(MLX_P, WIN_P, 100, 250, RED, fdf->text);
	free(fdf->text);
	fdf->text = ft_strdup("                                            +/-");
	mlx_string_put(MLX_P, WIN_P, 100, 250, YELLOW, fdf->text);
	free(fdf->text);
}

void	draw_map(t_fdf fdf)
{
	fdf.x_axis = 0;
	fdf.y_axis = 0;
	fdf.camera = "ROTATE";
	fdf.move_x = 0;
	fdf.move_y = 0;
	fdf.step = 3;
	put_init(&fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close2, &fdf);
	mlx_key_hook(fdf.win_ptr, key_hook, &fdf);
	mlx_hook(fdf.win_ptr, 6, 0, ft_mouse, &fdf);
	mlx_hook(fdf.win_ptr, 4, 0, ft_mouse_press, &fdf);
	mlx_hook(fdf.win_ptr, 5, 0, ft_mouse_releas, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
