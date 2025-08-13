/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:13:31 by mucabrin          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:38 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "bonjour";
	const char	c = 0;
	char		*p;
	p = ft_strrchr(str, c);
	printf("String starting from %c is: %s\n", c, p);
	return (0);
}*/
