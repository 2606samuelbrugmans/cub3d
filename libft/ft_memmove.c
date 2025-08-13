/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:28:47 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/30 00:44:06 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*ptr;
	char		*rtp;

	if (!dst || !src)
		return (NULL);
	ptr = src;
	rtp = dst;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else if (dst > src)
	{
		while (len--)
			rtp[len] = ptr[len];
	}
	return (dst);
}

// int    main(void)
// {
//     char dest[] = "oldstring";
//    const char src[]  = "newstring";

//    printf("Before memmove dest = %s, src = %s\n", dest, src);
//    ft_memmove(dest, src, 9);
//    printf("After memmove dest = %s, src = %s\n", dest, src);

//    return(0);
// }