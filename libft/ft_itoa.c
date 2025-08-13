/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:21:09 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/29 23:14:56 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	else if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*itoa;

	nb = n;
	i = ft_nblen(nb);
	itoa = ft_calloc(sizeof(char), i + 1);
	if (!itoa)
		return (0);
	if (nb == 0)
	{
		itoa[0] = 48;
		return (itoa);
	}
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		itoa[--i] = 48 + nb % 10;
		nb /= 10;
	}
	return (itoa);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	return (0);
}*/
