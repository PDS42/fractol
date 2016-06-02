/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:55:12 by prichard          #+#    #+#             */
/*   Updated: 2016/06/02 16:20:02 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	set_image(t_mlx *mlx)
{
	t_img	img;

	img.ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	img.size_line = mlx->width;
	img.mlx_width = mlx->width;
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.end);
	return (img);
}
