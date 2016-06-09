/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 18:16:12 by prichard          #+#    #+#             */
/*   Updated: 2016/06/09 15:44:59 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, int x, int y, t_all *all)
{
	ALL->zoom_x = (x * (ALL->x2 - ALL->x1) / (double)all->mlx->width + ALL->x1);
	ALL->zoom_y = (y * (ALL->y2 - ALL->y1) / (double)all->mlx->width + ALL->y1);
	if (key == 5)
	{

		ALL->x1 = (double)ALL->zoom_x + (ALL->x1 - ALL->zoom_x) * 1.1;
		ALL->x2 = (double)ALL->zoom_x + (ALL->x2 - ALL->zoom_x) * 1.1;
		ALL->y1 = (double)ALL->zoom_y + (ALL->y1 - ALL->zoom_y) * 1.1;
		ALL->y2 = (double)ALL->zoom_y + (ALL->y2 - ALL->zoom_y) * 1.1;
	}
	if (key == 4)
	{
		ALL->x1 = (double)ALL->zoom_x + (ALL->x1 - ALL->zoom_x) / 1.1;
		ALL->x2 = (double)ALL->zoom_x + (ALL->x2 - ALL->zoom_x) / 1.1;
		ALL->y1 = (double)ALL->zoom_y + (ALL->y1 - ALL->zoom_y) / 1.1;
		ALL->y2 = (double)ALL->zoom_y + (ALL->y2 - ALL->zoom_y) / 1.1;
	}
}

int		mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == 4 || button == 5)
		zoom(button, x, y, all);
	draw(all);
	return (0);
}
