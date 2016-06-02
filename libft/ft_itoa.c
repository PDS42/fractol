/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <prichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:09:02 by prichard          #+#    #+#             */
/*   Updated: 2016/05/28 17:51:23 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrsign(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

int			ft_abs(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		return (nb);
	}
	return (nb);
}

char		*ft_itoa(int n)
{
	int			nlen;
	int			sign;
	char		*str;

	nlen = ft_nbrlen(n);
	sign = ft_nbrsign(n);
	if (!(str = (char *)malloc(sizeof(char) * (nlen + sign + 1))))
		return (NULL);
	if (str)
	{
		str = str + nlen + sign;
		*str = '\0';
		if (n < 0)
			n = -n;
		if (n == 0)
			*--str = '0';
		while (n != 0)
		{
			*--str = ft_abs(n % 10) + '0';
			n = n / 10;
		}
		if (sign)
			*--str = '-';
	}
	return (str);
}
