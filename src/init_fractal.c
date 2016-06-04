/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:42:13 by prichard          #+#    #+#             */
/*   Updated: 2016/06/04 14:34:00 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		*init_fract_struct(t_all *all, char *argv)
{
	ft_putnbr(all->img->mlx_width);
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		all->fract = mandel(all);
	all->fract = mandel(all);
	   /* else if (ft_strcmp(argv, "Julia") == 0)*/
		/*fractal = //fonction julia ;*/
	return (all->fract);
}

t_fract		*mandel(t_all *all)
{
	all->fract->x1 = -2.1;
	all->fract->x2 = 0.6;	
	all->fract->y1 = -1.2;
	all->fract->y2 = 1.2;
	all->fract->zoom = 100; //a changer
	all->fract->iter_max = 40;
	all->fract->id = 0;
	ft_putnbr(all->mlx->width);
	return (all->fract);
}
