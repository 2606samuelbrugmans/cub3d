/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:38:15 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/30 22:46:09 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (char) c)
	{
		if (s[i] == 0)
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

// int	main(void)
// {
// 	const char	str[] = "This is just a String";
// 	const char	c = 's';
// 	char		*p;
// 	p = ft_strchr(NULL, -6);
// 	printf("String starting from %c is: %s\n", c, p);
// 	return (0);
// }
