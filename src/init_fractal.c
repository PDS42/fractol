/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:42:13 by prichard          #+#    #+#             */
/*   Updated: 2016/06/09 16:49:57 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		*init_fract_struct(t_all *all, char *argv)
{
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		all->fract = mandel(all);
	else if (ft_strcmp(argv, "Julia") == 0)
		all->fract = julia(all);
	else if (ft_strcmp(argv, "Ship") == 0)
		all->fract = ship(all);
	else
	{
		ft_putendl("Wrong argument type. Use :");
		ft_putendl("./fractol Mandelbrot");
		ft_putendl("or");
		ft_putendl("./fractol Julia");
		ft_putendl("or");
		ft_putendl("./fractol Ship");
		exit(0);
	}
	return (all->fract);
}

t_fract		*mandel(t_all *all)
{
	all->fract->x1 = -2.1;
	all->fract->x2 = 0.6;
	all->fract->y1 = -1.2;
	all->fract->y2 = 1.2;
	all->fract->zoom = 1000;
	all->fract->iter_max = 40;
	all->fract->id = 0;
	return (ALL);
}

t_fract		*julia(t_all *all)
{
	all->fract->tmpd = 0.285;
	all->fract->tmpd2 = 0.01;
	all->fract->x1 = -1.5;
	all->fract->x2 = 1.5;
	all->fract->y1 = -1.5;
	all->fract->y2 = 1.5;
	all->fract->zoom = 1000;
	all->fract->iter_max = 70;
	all->fract->id = 1;
	all->fract->zoom_x = (double)all->mlx->width / (ALL->x2 - ALL->x1);
	all->fract->zoom_y = (double)all->mlx->height / (ALL->y2 - ALL->y1);
	return (ALL);
}

t_fract		*ship(t_all *all)
{
	all->fract->x1 = -2.1;
	all->fract->x2 = 0.6;
	all->fract->y1 = -1.2;
	all->fract->y2 = 1.2;
	all->fract->zoom = 1000;
	all->fract->iter_max = 40;
	all->fract->id = 2;
	return (ALL);
}
