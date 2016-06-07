/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:42:13 by prichard          #+#    #+#             */
/*   Updated: 2016/06/07 13:40:01 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		*init_fract_struct(t_all *all, char *argv)
{
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		all->fract = mandel(all);
	else if (ft_strcmp(argv, "Julia") == 0)
		all->fract = julia(all);
	else
	{
		ft_putendl("Wrong argument type. Use Mandelbrot | Julia");
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
	/*all->fract->zoom = all->mlx->width / (ALL->x2 - ALL->x1);*/
	all->fract->zoom = 1000;
	all->fract->iter_max = 40;
	all->fract->id = 0;
	return (all->fract);
}

t_fract		*julia(t_all *all)
{
	ALL->x1 = -1.5;
	ALL->x2 = 1.5;
	ALL->y1 = -1.5;
	ALL->y2 = 1.5;
	ALL->zoom = 1000;
	ALL->iter_max = 70;
	ALL->id = 1;
	return (ALL);
}
