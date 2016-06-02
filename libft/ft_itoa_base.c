/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:11:01 by prichard          #+#    #+#             */
/*   Updated: 2016/04/30 18:33:34 by prichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	int		len;
	int		sign;
	char	*str;

	len = ft_nbrlen(n);
	sign = n < 0 ? 1 : 0;
	str = (char *)ft_memalloc(sizeof(char) * (len + sign + 1));
	str = str + len + sign;
	*str = '\0';
	if (n == 0)
		*--str = '0';
	while (n != 0)
	{
		*--str = "0123456789abcdef"[ft_abs(n % base)];
		n /= base;
	}
	if (sign)
		*--str = '-';
	return (str);
}
