/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:09:45 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/30 00:21:51 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	printf("%d\n", memcmp("", "o", 30));
// 	printf("%d\n", ft_memcmp(NULL, "o", 30));
// 	return (0);
// }