/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_iter_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:25:04 by prichard          #+#    #+#             */
/*   Updated: 2016/06/06 16:57:31 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_max_up(t_all *all)
{
	ALL->iter_max += 1;
	draw(all);
}

void	iter_max_down(t_all *all)
{
	if (ALL->iter_max > 0)
	{
		ALL->iter_max -= 1;
		draw(all);
	}
}

void	reset_fract(t_all *all)
{
	ALL = init_fract_struct(all, "Mandelbrot");
	ALL->iter_max = 40;
	draw(all);
}
