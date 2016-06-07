/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:03:02 by prichard          #+#    #+#             */
/*   Updated: 2016/06/07 18:20:10 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_left(t_all *all)
{
	ALL->x1 += 0.03;
	draw(all);
}

void	move_right(t_all *all)
{
	ALL->x1 -= 0.03;
	draw(all);
}

void	move_up(t_all *all)
{
	ALL->y1 += 0.03;
	draw(all);
}

void	move_down(t_all *all)
{
	ALL->y1 -= 0.03;
	draw(all);
}
