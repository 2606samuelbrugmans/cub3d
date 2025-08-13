/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:10 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/11 13:20:38 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
		int     c;

		c = 0;
		while (c <= 127)
		{
				printf("%d = %d\n", c, ft_isprint(c));
				c++;
		}
		printf("%d\n", ft_isprint(47));
}*/