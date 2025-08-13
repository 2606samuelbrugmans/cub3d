/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:22:56 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/31 17:37:47 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack || !needle)
		return (0);
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] && i + j < len)
			j++;
		if (needle[j] == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*to_find;
// 	char *p;

// 	str = "lorem ipsum dolor sit amet";
// 	to_find = "dolor";
// 	// printf("%s\n", strnstr(NULL, to_find, 0));
// 	p = ft_strnstr(str, to_find, 0);
// 	 printf("%s\n", ft_strnstr(str, to_find, 0));
// }
