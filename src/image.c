/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:55:12 by prichard          #+#    #+#             */
/*   Updated: 2016/06/04 17:05:59 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	*set_image(t_all *all)
{
   /* all->img->bpp = 4 * (sizeof(char));*/
	/*all->img->size_line = 1000 * all->img->bpp;*/
	/*all->img->end = 1;*/
	all->img->ptr = mlx_new_image(all->mlx->ptr, all->mlx->width, all->mlx->height);
	all->img->mlx_width = all->mlx->width;
	all->img->addr = mlx_get_data_addr(all->img->ptr, &all->img->bpp, &all->img->size_line, &all->img->end);
	return (all->img);
}
