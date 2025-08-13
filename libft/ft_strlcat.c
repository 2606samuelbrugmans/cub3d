/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:21:53 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/31 18:00:54 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstl;
	size_t	srcl;

	if (!src)
		return (0);
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	j = ft_strlen(dst);
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dstl)
		return (srcl + dstsize);
	while (i < dstsize - dstl - 1 && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (dstl + srcl);
}

// int	main(void)
// {
// 	char	dest[20] = "";
// 	char	src[20] = "";
// 	//printf("dest = %s, src = %s\n", dest, src);
// 	//printf("s = %s, l = %zu\n", src, ft_strlcat(NULL, src, 0));
// 	printf("s = %s, l = %zu\n", src, ft_strlcat(dest, NULL, 10));
// }