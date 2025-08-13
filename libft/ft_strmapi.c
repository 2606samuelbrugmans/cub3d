/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:34:18 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/19 23:16:53 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		size;

	if (!s || !f)
		return (0);
	i = 0;
	size = ft_strlen(s);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
char	ft_isodd(unsigned int i, char c)
{
	if (i % 2 == 0)
		c += 32;
	else
		c-=32;
	return (c);
}

int	main(void)
{
	printf("%s\n", ft_strmapi(NULL, ft_isodd));
	return (0);
}*/
