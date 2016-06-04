/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:40:38 by prichard          #+#    #+#             */
/*   Updated: 2016/06/03 14:36:18 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ESC_KEY 53

int		key_handler(int key, void *param)
{
	param = NULL;
	if (key == ESC_KEY)
		exit(0);
	return (0);
}
