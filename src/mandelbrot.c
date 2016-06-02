/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 16:23:49 by prichard          #+#    #+#             */
/*   Updated: 2016/06/02 17:19:59 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fract *mand, t_img *img)
{
	int		tmp;
	int		color;
	
	color = 0x00FFFF;
	mand->img_x = (mand->x2 - mand->x1) * mand->zoom;
	mand->img_y = (mand->y2 - mand->y1) * mand->zoom;
	mand->c.x = -1;
	mand->c.y = -1;
	while (++mand->c.x < mand->img_x)
	{
		while (++mand->c.y < mand->img_y)
		{
			mand->c_r = mand->c.x /mand->zoom + mand->x1;	
			mand->c_i = mand->c.y /mand->zoom + mand->y1;	
			mand->z_r = 0;
			mand->z_i = 0;
			mand->iter= 0;
			while ((mand->z_r * mand->z_r - mand->z_i * mand->z_i + mand->c_r) < 4
					&& mand->iter < mand->iter_max)
			{
				tmp = mand->z_r;
				mand->z_r = mand->z_r * mand->z_r - 
					mand->z_i * mand->z_i + mand->c_r;
				mand->z_i = 2 * mand->z_i * tmp + mand->c_i;
				mand->iter++;
				if (mand->iter == mand->iter_max)
					put_pixel_to_image(img, mand->c.y, mand->c.x, color);
				else
					put_pixel_to_image(img, mand->c.y, mand->c.x, color);
			}
		}
	}
}
