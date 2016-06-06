/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:58:05 by prichard          #+#    #+#             */
/*   Updated: 2016/06/06 18:37:28 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_hook(t_all *all, t_coord c)
{
	double	center;
	double	shift;
	double	tmp;

	center = (ALL->x1 + ALL->x2) / 2;
	shift = ((double)c.x / ALL->zoom) + ALL->x1 - center;
	tmp = ALL->x1;
	ALL->x1 = (ALL->x1 + shift) + ((ALL->x2 - ALL->x1) / 5);
	ALL->x2 = (ALL->x2 + shift) - ((ALL->x2 - tmp) / 5);
	center = (ALL->y1 + ALL->y2) / 2;
	shift = ((double)c.y / ALL->zoom) + ALL->y1 - center;
	tmp = ALL->y1;
	ALL->y1 = (ALL->y1 + shift) + ((ALL->y2 - ALL->y1) / 5);
	ALL->y2 = (ALL->y2 + shift) - ((ALL->y2 - tmp) / 5);
	ALL->zoom = all->mlx->width / (ALL->x2 - ALL->x1);
	ALL->iter_max += 1;
	draw(all);
}

void	unzoom_hook(t_all *all, t_coord c)
{
	double	center;
	double	shift;
	double	tmp;

	center = (ALL->x1 + ALL->x2) / 2;
	shift = ((double)c.x / ALL->zoom) + ALL->x1 - center;
	tmp = ALL->x1;
	ALL->x1 = (ALL->x1 + shift) - ((ALL->x2 - ALL->x1) / 5);
	ALL->x2 = (ALL->x2 + shift) + ((ALL->x2 - tmp) / 5);
	center = (ALL->y1 + ALL->y2) / 2;
	shift = ((double)c.y / ALL->zoom) + ALL->y1 - center;
	tmp = ALL->y1;
	ALL->y1 = (ALL->y1 + shift) - ((ALL->y2 - ALL->y1) / 5);
	ALL->y2 = (ALL->y2 + shift) + ((ALL->y2 - tmp) / 5);
	ALL->zoom = all->mlx->width / (ALL->x2 - ALL->x1);
	ALL->iter_max += 1;
	draw(all);
}
