/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 16:09:36 by prichard          #+#    #+#             */
/*   Updated: 2016/06/06 18:27:34 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "libft.h"
#define ALL all->fract

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_fract
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	float		zoom;//mb pb
	int			iter_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			iter;
	int			id;
	t_coord		c;
}				t_fract;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		height;
	int		width;
	char	*filename;
}				t_mlx;

typedef struct	s_img
{
	void	*ptr;
	void	*addr;
	int		bpp;
	int		size_line;
	int		end;
	int		mlx_width;
}				t_img;

typedef struct	s_all
{
	t_mlx	*mlx;
	t_img	*img;
	t_fract	*fract;
	t_coord	*coord;
}				t_all;

/*
**Fonctions
*/

void	draw_mandelbrot(t_all *all);
int		draw(t_all *all);
t_img	*set_image(t_all *all);
int		key_handler(int key, t_all *all);
void	key_funct(int key, t_all *all);
t_fract	*mandel(t_all *all);
t_fract	*init_fract_struct(t_all *all, char *argv);
void	put_pixel_to_image(t_img *img, int y, int x, int color);
t_all	*init_all(t_all *all);
void	mandel_compl(t_all *all, int x, int y);
void	mandel_values(t_all *all, int x, int y);

/*
** move.c
*/

void	move_left(t_all *all);
void	move_right(t_all *all);
void	move_up(t_all *all);
void	move_down(t_all *all);

/*
** modify_iter_max.c
*/

void	iter_max_up(t_all *all);
void	iter_max_down(t_all *all);
void	reset_fract(t_all *all);

/*
**	zoom.c
*/

void	zoom_hook(t_all *all, t_coord coord);
void	unzoom_hook(t_all *all, t_coord coord);

/*
** mouse_hook.c
*/

int		mouse_hook(int button, int x, int y, t_all *all);
void	mouse_funct(int button, t_coord mouse_pos, t_all *all);

#endif
