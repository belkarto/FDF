/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:25:29 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/15 21:39:19 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"
#include <math.h>

void	ft_corr(t_fdf *fdf)
{
	int		cor;
	char	*text;

	mlx_string_put(MLX_P, WIN_P, 25, 330, \
	RED, "                 X         Y  ");
	mlx_string_put(MLX_P, WIN_P, 25, 350, \
	RED, "CORDINATION  [       ] [       ]");
	cor = fdf->move_x;
	text = ft_itoa(cor);
	mlx_string_put(MLX_P, WIN_P, 180, 350, YELLOW, text);
	free(text);
	cor = fdf->move_y;
	text = ft_itoa(cor);
	mlx_string_put(MLX_P, WIN_P, 265, 350, YELLOW, text);
	free(text);
}

void	ft_degree(t_fdf *fdf)
{
	int		degree;
	char	*text;

	degree = (M_PI / 4 * fdf->x_axis) * (180 / M_PI * fdf->x_axis);
	mlx_string_put(MLX_P, WIN_P, 25, 370, RED, "X AXIS:");
	text = ft_itoa(degree);
	mlx_string_put(MLX_P, WIN_P, 125, 370, YELLOW, text);
	free(text);
	degree = (M_PI / 4 * fdf->y_axis) * (180 / M_PI * fdf->y_axis);
	mlx_string_put(MLX_P, WIN_P, 25, 390, RED, "Y AXIS:");
	text = ft_itoa(degree);
	mlx_string_put(MLX_P, WIN_P, 125, 390, YELLOW, text);
	free(text);
}

void	guide(t_fdf *fdf)
{
	mlx_string_put(MLX_P, WIN_P, 110, 5, RED, "---- GUIDE: ----");
	mlx_string_put(MLX_P, WIN_P, 10, 35, RED, "I = ISOMITRIC");
	mlx_string_put(MLX_P, WIN_P, 10, 55, RED, "p = PARALLEL");
	mlx_string_put(MLX_P, WIN_P, 10, 75, RED, "F = FRONT");
	mlx_string_put(MLX_P, WIN_P, 10, 95, RED, "R = RESET KEY");
	mlx_string_put(MLX_P, WIN_P, 10, 115, RED, "+ = INCREASE HEIGHT");
	mlx_string_put(MLX_P, WIN_P, 10, 135, RED, "- = DECREASE HEIGHT");
	mlx_string_put(MLX_P, WIN_P, 10, 155, RED, "SCROLL = ZOOM IN/OUT");
	mlx_string_put(MLX_P, WIN_P, 10, 175, RED, "A/W/S/D = ROTATION");
}

void	ft_menu(t_fdf *fdf)
{
	char	*text;

	guide(fdf);
	mlx_string_put(MLX_P, WIN_P, 110, 200, RED, "---- INFO: ----");
	mlx_string_put(MLX_P, WIN_P, 25, 250, RED, "SCALE : ");
	text = ft_itoa(fdf->step);
	mlx_string_put(MLX_P, WIN_P, 100, 250, YELLOW, text);
	free(text);
	mlx_string_put(MLX_P, WIN_P, 25, 300, RED, "ALTITUDE : ");
	text = ft_itoa(fdf->h_step);
	mlx_string_put(MLX_P, WIN_P, 125, 300, YELLOW, text);
	free(text);
	ft_corr(fdf);
	ft_degree(fdf);
}
