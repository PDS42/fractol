/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:23:56 by prichard          #+#    #+#             */
/*   Updated: 2016/06/07 18:40:32 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_menu(t_all *all)
{
	mlx_string_put(all->mlx->ptr, all->mlx->win, 140, 40, 0xFFFFFF, "--CONTROLS--");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 60, 0xFFFFFF,
		   	"-Press '+' or '-' to change max iterations");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 80, 0xFFFFFF, 
			"-Press arrow keys to move and change size");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 100, 0xFFFFFF,
		   	"-Press 'm' to switch to Mandelbrot");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 120, 0xFFFFFF,
		   	"-Press 'j' to switch to Julia");
	mlx_string_put(all->mlx->ptr, all->mlx->win, 10, 140, 0xFFFFFF,
		   	"-Press 'p' to switch to Glynn");
}
