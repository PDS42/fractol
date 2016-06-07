/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:40:38 by prichard          #+#    #+#             */
/*   Updated: 2016/06/07 18:40:41 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ESC_KEY 53

int		key_handler(int key, t_all *all)
{
	if (key == ESC_KEY)
		exit (0);
	if (key == 126 || key == 125 || key == 124 || key == 123 || key == 69
			|| key == 78 || key == 76 || key == 5 || key == 4 || key == 46)
	{
		mlx_destroy_image(all->mlx->ptr, all->img->ptr);
		all->img->ptr = mlx_new_image(all->mlx->ptr, all->mlx->width, all->mlx->height);
		all->img->addr = mlx_get_data_addr(all->img->ptr, &all->img->bpp, 
				&all->img->size_line, &all->img->end);
	}
	key_funct(key, all);
	key_funct2(key, all);
	return (0);
}

void	key_funct(int key, t_all *all)
{
	if (key == 126)
		move_up(all);
	if (key == 125)
		move_down(all);
	if (key == 123)
		move_left(all);
	if (key == 124)
		move_right(all);
	if (key == 69)
		iter_max_up(all);
	if (key == 78)
		iter_max_down(all);
	if (key == 46)
	{
		ALL = init_fract_struct(all, "Mandelbrot");
		draw(all);
	}
}

void	key_funct2(int key, t_all *all)
{
	if (key == 38)
	{
		ALL = init_fract_struct(all, "Julia");
		draw(all);
	}
	if (key == 35)
	{
		ALL = init_fract_struct(all, "Glynn");
		draw(all);
	}
}
