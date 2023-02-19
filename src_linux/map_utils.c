/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:21:56 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/19 17:52:12 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linux_fdf.h"
#include <stdlib.h>

int	line_size(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			len++;
			i++;
		}
		while (str[i] != ' ' && str[i])
			i++;
		while (str[i] == ' ' && str[i])
			i++;
	}
	return (len);
}

char	***map_geter(char **str, int hight, int *len)
{
	int		i;
	char	***map;

	i = -1;
	*len = line_size(str[0]);
	while (str[++i])
	{
		if (line_size(str[i]) != *len)
		{
			ft_putstr_fd("Invalid map diffrent line size\n", 2);
			exit(1);
		}
	}
	i = -1;
	map = (char ***)ft_calloc(hight + 1, sizeof(char **));
	while (++i < hight)
		map[i] = ft_split(str[i], ' ');
	ft_free1(str);
	return (map);
}

int	get_step(t_fdf *fdf)
{
	int	step;

	if (fdf->map_high > fdf->map_width)
	{
		step = (WIN_H / fdf->map_high);
		if (step == 1)
			return (2);
		else
			return (step);
	}
	else
	{
		step = (WIN_W / fdf->map_width);
		if (step == 1)
			return (2);
		else
			return (step);
	}
}

void	get_points(char	*str, t_fdf *fdf)
{
	int		i;
	int		j;
	char	***map;

	map = map_geter(ft_split(str, '\n'), fdf->map_high, &fdf->map_width);
	free(str);
	j = -1;
	(*fdf).pnt = ft_calloc(fdf->map_high + 1, sizeof(t_point *));
	(*fdf).pnt_af = ft_calloc(fdf->map_high + 1, sizeof(t_point *));
	fdf->step = 5;
	while (++j < fdf->map_high)
	{
		fdf->pnt[j] = ft_calloc(fdf->map_width + 1, sizeof(t_point));
		fdf->pnt_af[j] = ft_calloc(fdf->map_width + 1, sizeof(t_point));
		i = -1;
		while (++i < fdf->map_width)
		{
			fdf->pnt[j][i].p_x = (i * fdf->step);
			fdf->pnt[j][i].p_y = (j * fdf->step);
			fdf->pnt[j][i].h = ft_atoi(map[j][i]);
			fdf->pnt[j][i].p_color = get_color(map[j][i], fdf->pnt[j][i].h);
		}
	}
	ft_free(map);
}

void	read_map(int fd, char *str, t_fdf *fdf)
{
	char	*prefix;
	char	*readed;
	char	*line;

	prefix = ft_strrchr(str, 'f');
	if (prefix == NULL || ft_strncmp(prefix - 3, ".fdf", 4) != 0)
	{
		ft_putstr_fd("Invalid file type, only (.fdf) files\n", 2);
		exit (1);
	}
	fdf->map_high = 0;
	readed = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		readed = ft_strjoin_gnl(readed, line);
		free(line);
		fdf->map_high++;
	}
	get_points(readed, fdf);
}
