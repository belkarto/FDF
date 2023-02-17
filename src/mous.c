/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mous.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:32:44 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/15 20:55:09 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_mouse(int x, int y, t_fdf *fdf)
{
	if (x < WIN_W && x > 0 && y > 0 && y < WIN_H
		&& fdf->mouse_down == 1)
	{
		if (x > fdf->mouse_x)
			fdf->move_x += x - fdf->mouse_x;
		else if (x < fdf->mouse_x)
			fdf->move_x -= fdf->mouse_x - x;
		if (y > fdf->mouse_y)
			fdf->move_y += y - fdf->mouse_y;
		else if (y < fdf->mouse_y)
			fdf->move_y -= fdf->mouse_y - y;
		rerander(*fdf, &fdf->img);
	}
	fdf->mouse_x = x;
	fdf->mouse_y = y;
	return (0);
}

int	ft_mouse_releas(int key, int x, int y, t_fdf *fdf)
{
	x++;
	y++;
	if (key == 1)
		fdf->mouse_down = 0;
	return (0);
}

int	ft_mouse_press(int key, int x, int y, t_fdf *fdf)
{
	if (key == 5 && fdf->step < 1000)
	{
		fdf->step++;
		if (ft_strncmp(fdf->camera, "ROTATE", ft_strlen("ROTATE")) == 0)
			rotat(fdf);
		else
			iso(fdf);
	}
	if (key == 4 && fdf->step > 1)
	{
		fdf->step--;
		if (ft_strncmp(fdf->camera, "ROTATE", ft_strlen("ROTATE")) == 0)
			rotat(fdf);
		else
			iso(fdf);
	}
	if (key == 1)
	{
		fdf->mouse_down = 1;
		fdf->mouse_x = x;
		fdf->mouse_y = y;
	}
	rerander(*fdf, &fdf->img);
	return (0);
}
