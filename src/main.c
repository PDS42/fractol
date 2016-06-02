/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 17:04:55 by prichard          #+#    #+#             */
/*   Updated: 2016/06/02 17:19:36 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	mlxinit(int width, int height, char *name)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, width, height, name);
	mlx.height = height;
	mlx.width = width;
	return (mlx);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;
	t_fract	fract;

	if (ac == 2)
	{
		mlx = mlxinit(1000, 1000, "fractol");
		img = set_image(&mlx);
		fract = *init_fract_struct(av[1]); 
		draw_mandelbrot(&fract, &img);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
		mlx_hook(mlx.win, 2, 0, key_handler, &fract);
		mlx_loop(mlx.ptr);
		return (0);
	}
	return (0);
}
