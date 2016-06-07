/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 18:16:12 by prichard          #+#    #+#             */
/*   Updated: 2016/06/07 11:39:36 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int		mouse_hook(int button, int x, int y, t_all *all)*/
/*{*/
	/*t_coord		mouse_pos;*/

	/*mouse_pos.x = x;*/
	/*mouse_pos.y = y;*/
	/*if (button == 47 || button == 43)*/
	/*{*/
		/*mlx_destroy_image(all->mlx->ptr, all->img->ptr);*/
		/*all->img->ptr = mlx_new_image(all->mlx->ptr, all->mlx->width,*/
				   /*all->mlx->height);*/
		/*all->img->addr = mlx_get_data_addr(all->img->ptr, &all->img->bpp,*/
				/*&all->img->size_line, &all->img->end);*/
	/*}*/
	/*mouse_funct(button, mouse_pos, all);*/
	/*return (0);*/
/*}*/

/*void	mouse_funct(int button, t_coord mouse_pos, t_all *all)*/
/*{*/
	/*if (button == 47)*/
		/*zoom_hook(all, mouse_pos);*/
	/*if (button == 43)*/
		/*unzoom_hook(all, mouse_pos);*/
/*}*/

int		mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == 4 || button == 5)
	{
		ALL->x1 += (((double)x - all->mlx->height / 2 ) / all->mlx->width / 2)
			/ ALL->zoom * 10;

		ALL->x2 += (((double)x - all->mlx->height / 2 ) / all->mlx->width / 2)
			/ ALL->zoom * 10;
		ALL->y1 += (((double)y - all->mlx->width / 2 ) / all->mlx->height / 2)
			/ ALL->zoom * 10;
		ALL->y2 += (((double)y - all->mlx->width / 2 ) / all->mlx->height / 2)
			/ ALL->zoom * 10;
	}
	if (button == 5)
		ALL->zoom *= 1.1;
	else if (button == 4)
		ALL->zoom /= 1.1;
	draw(all);
	return (0);
}
