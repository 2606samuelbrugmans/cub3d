/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:16:42 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/11 13:17:12 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
				printf("%c = %d\n", c, ft_isdigit(c));
				c++;
		}
		printf("%d\n", ft_isdigit(47));
}*/