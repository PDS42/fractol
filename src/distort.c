/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:26:33 by prichard          #+#    #+#             */
/*   Updated: 2016/06/08 11:32:35 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	distort_left(t_all *all)
{
	ALL->x1 += 0.03;
	draw(all);
}

void	distort_right(t_all *all)
{
	ALL->x1 -= 0.03;
	draw(all);
}

void	distort_up(t_all *all)
{
	ALL->y1 += 0.03;
	draw(all);
}

void	distort_down(t_all *all)
{
	ALL->y1 -= 0.03;
	draw(all);
}
