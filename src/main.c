/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:21:12 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/15 21:27:33 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

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
		ft_printf("ERROR:\tusage:\n\t./fdf <map name>");
	fd = check(open(argv[1], O_RDONLY), __FILE__, __LINE__);
	read_map(fd, argv[1], &fdf);
	fdf.camera = "ISO";
	draw_map(fdf);
	return (0);
}
