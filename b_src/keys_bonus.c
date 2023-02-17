/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:43:26 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/15 20:47:29 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	height_control(t_fdf *fdf, int key)
{
	if (key == K_PLUS)
		fdf->h_step++;
	else if (key == K_MINUS)
		fdf->h_step--;
	if (ft_strncmp(fdf->camera, "ROTATE", ft_strlen("ROTATE")) == 0)
		rotat(fdf);
	else
		iso(fdf);
}

void	rotation_control(t_fdf *fdf, int key)
{
	if (key == K_W || key == 65362)
		fdf->y_axis += 0.05;
	else if (key == K_S)
		fdf->y_axis -= 0.05;
	else if (key == K_A)
		fdf->x_axis += 0.05;
	else if (key == K_D)
		fdf->x_axis -= 0.05;
	else if (key == K_E)
	{
		fdf->x_axis += 0.1;
		fdf->y_axis += 0.1;
	}
	else if (key == K_Q)
	{
		fdf->x_axis -= 0.1;
		fdf->y_axis -= 0.1;
	}
	if (ft_strncmp(fdf->camera, "ROTATE", ft_strlen("ROTATE")) == 0)
		rotat(fdf);
	else
		iso(fdf);
}

void	iso_key(t_fdf *fdf, int key)
{
	if (key == K_I)
	{
		fdf->x_axis = 1;
		fdf->y_axis = 0.8;
		fdf->camera = "ISO";
	}
	else if (key == K_P || key == 112)
	{
		fdf->x_axis = 1;
		fdf->y_axis = 0;
		fdf->camera = "ISO";
	}
	iso(fdf);
}

void	reset(t_fdf *fdf)
{
	fdf->x_axis = 0;
	fdf->y_axis = 0;
	fdf->camera = "ROTATE";
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->step = 5;
	fdf->h_step = 0;
	rotat(fdf);
}
