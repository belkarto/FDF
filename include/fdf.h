/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:43:59 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/15 21:10:27 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include "./my_lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

# define WIN_W 1920
# define WIN_H 1080
//----CCOLORS----//
# define WHITHE	0X00ffffff
# define BLACK	0X00000000
# define RED	0X00ff0000
# define BLEU	0X000000ff
# define GREEN	0X0000ff00
# define ORANGE 0X00ff7000
# define YELLOW	0X00ffff00
//-----RGB MACROS---//
# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)
# define MLX_P fdf->mlx_ptr
# define WIN_P fdf->win_ptr
//----KEYS MACROS----//
# define K_P 35
# define K_I 34
# define K_R 15
# define K_PLUS 24
# define K_MINUS 27
# define K_Q 12
# define K_W 13
# define K_E 14
# define K_F 3
# define K_S 1
# define K_A 0
# define K_D 2
# define ESC 53

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_point
{
	int	p_x;
	int	p_y;
	int	p_color;
	int	h;
}	t_point;

typedef struct s_fdf
{
	t_point	**pnt;
	t_point	**pnt_af;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*camera;
	char	*text;
	t_img	img;
	int		map_high;
	int		map_width;
	int		step;
	int		max_h;
	int		h_step;
	float	x_axis;
	float	y_axis;
	int		mouse_x;
	int		mouse_y;
	int		move_x;
	int		move_y;
	int		mouse_down;
}	t_fdf;

typedef struct s_bres
{
	int	dx;
	int	dy;
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	color;
	int	color1;
	int	color2;
}	t_bres;

int		color_picker(int h);
int		get_color(const char *str, int h);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		key_hook(int key, t_fdf *data);
int		close2(int key, t_fdf *data);
int		ft_mouse(int x, int y, t_fdf *fdf);
int		ft_mouse_releas(int key, int x, int y, t_fdf *fdf);
int		ft_mouse_press(int key, int x, int y, t_fdf *fdf);
void	read_map(int fd, char *str, t_fdf *fdf);
void	ft_free1(char **str);
void	ft_free(char ***str);
void	projection(t_fdf *fdf);
void	put_line_low(t_point p1, t_point p2, t_img *img);
void	put_line_high(t_point p1, t_point p2, t_img *img);
void	put_line(t_point p1, t_point p2, t_img *img);
void	iso(t_fdf *fdf);
void	iso_key(t_fdf *fdf, int key);
void	height_control(t_fdf *fdf,int key);
void	rotation_control(t_fdf *fdf, int key);
void	reset(t_fdf *fdf);
void	rotat(t_fdf *fdf);
void	put_map(t_fdf fdf, t_img *img);
void	rerander(t_fdf fdf, t_img *img);
void	draw_map(t_fdf fdf);
void	ft_menu_win(t_img *img);
void	ft_menu(t_fdf *fdf);
#endif
