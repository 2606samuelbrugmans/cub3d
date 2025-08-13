/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:39:19 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/31 18:03:07 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char str[] = "";
// 	const char str2[] = "";
// 	const char c = 'h';
// 	const char c2 = 'h';
// 	char *ret;
// 	char *ret2;

// 	ret = memchr(str + 5, c, 10);
// 	printf("String after    |%c| is - |%s|\n", c, ret);
// 	ret2 = ft_memchr(NULL, c2, 10);
// 	printf("String after ft |%c| is - |%s|\n", c2, ret2);
// 	return (0);
// }