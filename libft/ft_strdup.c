/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:14:44 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/31 18:01:39 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// int	main(void)
// {
// 	char	*src;
// 	char	*dest;
// 	char	*dest2;

// 	src = "Hello, World!";
// 	dest = ft_strdup(NULL);
// 	dest2 = strdup(src);
// 	printf("src = %s\n", src);
// 	printf("ft %s\n", ft_strdup(NULL));
// 	printf("   %s\n", strdup(src));
// }
