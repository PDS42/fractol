/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:25:25 by prichard          #+#    #+#             */
/*   Updated: 2016/06/07 18:47:22 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_glynn(t_all *all)
{
	double	tmp;

	ALL->c.x = -1;
	while (++ALL->c.x < all->mlx->width)
	{
		ALL->c.y = -1;
		while (++ALL->c.y < all->mlx->height)
		{
			glynn_values(all, ALL->c.x, ALL->c.y);
			while (sqrt((ALL->z_r * ALL->z_r) + (ALL->z_i * ALL->z_i)
					   	+ ALL->c_r) < 4 && ++ALL->iter < ALL->iter_max)
			{
				tmp = ALL->z_r;
				ALL->z_r = sqrt((ALL->z_r * ALL->z_r - ALL->z_i * ALL->z_i) *
						(ALL->z_r *ALL->z_r - ALL->z_i * ALL->z_i)) + ALL->c_r;
				ALL->z_i = sqrt((2 * ALL->z_i * tmp) * (2 * ALL->z_i * tmp))
					+ ALL->c_i;
			}
			mandel_compl(all, ALL->c.x, ALL->c.y);
		}
	}
	mlx_put_image_to_window(all->mlx->ptr, all->mlx->win, all->img->ptr, 0, 0);
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 10, 0xFFFFFF, "iter max:");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 140, 10, 0xFFFFFF,
			ft_itoa(ALL->iter_max));
	print_menu(all);
}
