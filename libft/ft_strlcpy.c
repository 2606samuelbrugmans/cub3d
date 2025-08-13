/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:27:50 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/30 23:09:05 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcl;

	if (!dst || !src)
		return (0);
	i = 0;
	srcl = ft_strlen(src);
	if (dstsize == 0)
		return (srcl);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srcl);
}

// int	main(void)
// {
// 	char	dest[20] = "Hellooo";
// 	char	*src;

// 	src = "world!";
// 	printf("dest = %s, src = %s\n", dest, src);
// 	// ft_strlcpy(dest, src, 3);
// 	printf("d = %s, s = %s sl = %zu\n", dest, src, ft_strlcpy(NULL, NULL, 5));
// }