/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:23:56 by prichard          #+#    #+#             */
/*   Updated: 2016/06/08 17:26:55 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_menu(t_all *all)
{
	mlx_string_put(all->mlx->ptr, all->mlx->win, 100, 30, 0xFFFFFF,
			"--CONTROLS--");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 50, 0xFFFFFF,
			"-Press 'ESC' to quit");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 70, 0xFFFFFF,
			"-Press '+' or '-' to change max iterations");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 90, 0xFFFFFF,
			"-Press arrow keys to move");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 110, 0xFFFFFF,
			"-Press WASD to expand fractals");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 130, 0xFFFFFF,
			"-Press 'm' to switch to Mandelbrot");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 150, 0xFFFFFF,
			"-Press 'j' to switch to Julia");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 170, 0xFFFFFF,
			"-Press 'p' to switch to Ship");
}
