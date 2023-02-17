/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:21:12 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/17 07:26:20 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"
#include <stdlib.h>

int	check(int x, char *file, int line)
{
	if (x == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(file, 2);
		ft_putchar_fd(32, 2);
		ft_putnbr_fd(line, 2);
		exit (1);
	}
	else
		return (x);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_printf("ERROR:\tusage:\n\t./fdf <map name>");
		exit(1);
	}
	fd = check(open(argv[1], O_RDONLY), __FILE__, __LINE__);
	read_map(fd, argv[1], &fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_W, WIN_H, "FDF");
	fdf.img.img = mlx_new_image(fdf.mlx_ptr, WIN_W, WIN_H);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, \
			&fdf.img.line_length, &fdf.img.endian);
	draw_map(fdf);
	return (0);
}
