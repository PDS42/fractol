/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 12:41:44 by prichard          #+#    #+#             */
/*   Updated: 2016/06/04 12:51:54 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_img *img, int y, int x, int color)
{
	/*ft_putnbr(img->mlx_width);*/
	((int*)(img->addr))[y * img->mlx_width + x] = color;
}
