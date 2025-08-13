/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:40 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/19 22:35:01 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	i = 0;
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (len > i)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = 0;
	return (substr);
}
/*
int	main(void)
{
	printf("%s\n", ft_substr(NULL, 3, 40));
	return (0);
}*/