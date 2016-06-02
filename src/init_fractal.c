/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:42:13 by prichard          #+#    #+#             */
/*   Updated: 2016/06/02 17:38:58 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		*init_fract_struct(char *argv)
{
	t_fract	*fractal;

	fractal = NULL;
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		fractal = mandel();
	fractal = mandel();
	   /* else if (ft_strcmp(argv, "Julia") == 0)*/
		/*fractal = //fonction julia ;*/
	return (fractal);
}

t_fract		*mandel(void)
{
	t_fract		*fract;

	fract = ft_memalloc(sizeof(t_fract));
	fract->x1 = -2.1;
	fract->x2 = 0.6;	
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	fract->zoom = 100; //a changer
	fract->iter_max = 40;
	fract->h = 1;
	fract->id = 0;
	return (fract);
}
