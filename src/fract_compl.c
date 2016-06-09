/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_compl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 12:31:57 by prichard          #+#    #+#             */
/*   Updated: 2016/06/09 14:26:13 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_compl(t_all *all, int x, int y)
{
	if (ALL->iter == ALL->iter_max)
		put_pixel_to_image(all->img, y, x,
				mlx_get_color_value(all->mlx->ptr, 0x000000));
	else
		put_pixel_to_image(all->img, y, x, mlx_get_color_value(all->mlx->ptr,
					ALL->iter * 255 / ALL->iter_max));
}

void	mandel_values(t_all *all, int x, int y)
{
	ALL->c_r = ((x * (ALL->x2 - ALL->x1)) / ALL->zoom + ALL->x1);
	ALL->c_i = ((y * (ALL->y2 - ALL->y1)) / ALL->zoom + ALL->y1);
	ALL->z_r = 0;
	ALL->z_i = 0;
	ALL->iter = -1;
}

void	julia_values(t_all *all, int x, int y)
{
	ALL->c_r = ALL->tmpd;
	ALL->c_i = ALL->tmpd2;
	ALL->z_r = ((x * (ALL->x2 - ALL->x1)) / ALL->zoom + ALL->x1);
	ALL->z_i = ((y * (ALL->y2 - ALL->y1)) / ALL->zoom + ALL->x1);
	ALL->iter = -1;
}

void	ship_values(t_all *all, int x, int y)
{
	ALL->c_r = ((x * (ALL->x2 - ALL->x1)) / ALL->zoom + ALL->x1);
	ALL->c_i = ((y * (ALL->y2 - ALL->y1)) / ALL->zoom + ALL->y1);
	ALL->z_r = 0;
	ALL->z_i = 0;
	ALL->iter = -1;
}
