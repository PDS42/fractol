/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_track.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:32:10 by prichard          #+#    #+#             */
/*   Updated: 2016/06/09 17:46:31 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_track(int x, int y, t_all *all)
{
	if (ALL->id == 1)
	{
		ALL->tmpd = -1 + 2 / (double)all->mlx->width * (double)x;
		ALL->tmpd2 = -1 + 2 / (double)all->mlx->height * (double)y;
	}
	draw(all);
	return (0);
}
