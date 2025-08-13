/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:13:33 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/20 19:55:38 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
				printf("%c = %d\n", c, ft_isalpha(c));
				c++;
		}
		printf("%d\n", ft_isalpha('3'));
}
*/