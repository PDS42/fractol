/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 16:09:36 by prichard          #+#    #+#             */
/*   Updated: 2016/06/04 18:09:50 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "libft.h"

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
	int			zoom;
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
t_img	*set_image(t_all *all);
int		key_handler(int keu, void *param);
t_fract	*mandel(t_all *all);
t_fract	*init_fract_struct(t_all *all, char *argv);
void	put_pixel_to_image(t_img *img, int y, int x, int color);
t_all	*init_all(t_all *all);

#endif
