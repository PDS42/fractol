/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 16:23:49 by prichard          #+#    #+#             */
/*   Updated: 2016/06/04 15:11:53 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_all *all)
{
	int		tmp;
	int		color;

	color = 0x00FFFF;
	all->fract->c.x = -1;
	while (++all->fract->c.x < 1000)
	{
		all->fract->c.y = -1;
		while (++all->fract->c.y < 1000)
		{
			all->fract->c_r = all->fract->c.x / all->fract->zoom + all->fract->x1;	
			all->fract->c_i = all->fract->c.y / all->fract->zoom + all->fract->y1;	
			all->fract->z_r = 0;
			all->fract->z_i = 0;
			all->fract->iter= 0;
			while (((all->fract->z_r * all->fract->z_r) - (all->fract->z_i * all->fract->z_i + all->fract->c_r)) < 4 && all->fract->iter < all->fract->iter_max)
			{
				tmp = all->fract->z_r;
				all->fract->z_r = (all->fract->z_r * all->fract->z_r) - 
					(all->fract->z_i * all->fract->z_i) + all->fract->c_r;
				all->fract->z_i = 2 * all->fract->z_i * tmp + all->fract->c_i;
				all->fract->iter++;
				if (all->fract->iter == all->fract->iter_max)
				{
					put_pixel_to_image(all->img, all->fract->c.y, 
							all->fract->c.x, 0xFFFFFF);
				}
				else
				{
					/*ft_putnbr(all->fract->c.x);*/
					/*ft_putchar('|');*/
					/*ft_putnbr(all->fract->c.y);*/
					/*ft_putchar('\n');*/
					put_pixel_to_image(all->img, all->fract->c.y, 
						all->fract->c.x, 0xFFFF00);
				}
			}
		}
	}
}

/*void    mandelbrot1(t_all *all, int t)*/
/*{*/
	/*int        x;*/
	/*int        y;*/
	/*int        i;*/

	/*x = -1;*/
	/*(t == 1) ? init_frac1(all) : 0;*/
	/*while (++x < MLX_SIZE_L)*/
	/*{*/
		/*y = -1;*/
		/*while (++y < MLX_SIZE_H)*/
		/*{*/
			/*i = -1;*/
			/*init_cord1(all, x, y);*/
			/*while (((all->c1->z_r * all->c1->z_r) + (all->c1->z_i **/
							/*all->c1->z_i)) < 4 && ++i < all->info1->imax)*/
			/*{*/
				/*all->c1->tmp = all->c1->z_r;*/
				/*all->c1->z_r = all->c1->z_r * all->c1->z_r -*/
					/*(all->c1->z_i * all->c1->z_i) + all->c1->c_r;*/
				/*all->c1->z_i = 2 * all->c1->z_i * all->c1->tmp + all->c1->c_i;*/
			/*}*/
			/*put_to_img1(all, x, y, i);*/
		/*}*/
	/*}*/
/*}*/
