/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:19:14 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/11 13:19:30 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
		int     c;

		c = 0;
		while (c <= 130)
		{
				printf("%d = %d\n", c, ft_isascii(c));
				c++;
		}
		printf("%d\n", ft_isascii(47));
}*/