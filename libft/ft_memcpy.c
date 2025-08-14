/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:25:11 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/30 00:41:23 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*ptr;
	char		*rtp;

	if (!dst || !src || n <= 0)
		return (NULL);
	i = 0;
	ptr = src;
	rtp = dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		rtp[i] = ptr[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char src[] = "Hello";
// 	char dst[1];
// 	char src2[] = "Hello";
// 	char dst2[1];

// 	// Use memcpy to copy the string to the buffer
// 	printf("%p\n", (char *)memcpy(dst, src, 3));
// 	printf("Using memcpy: %s\n", dst);
// 	printf("%p\n", (char *)ft_memcpy(dst2, NULL, 3));
// 	printf("Using ft_memcpy: %s\n", dst2);
// 	return (0);
// }