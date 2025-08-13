/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:22:07 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/20 19:59:26 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcheck(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strsub(const char *s, unsigned int start, int len)
{
	char	*str;
	int		i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = (s[start]);
		i++;
		start++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_setcheck(s1[start], set))
		start++;
	while ((ft_setcheck(s1[end], set)))
		end--;
	strtrim = ft_strsub (s1, start, end - (start - 1));
	return (strtrim);
}
/*
int	main(void)
{
	printf("%s\n", ft_strtrim(NULL, "b"));
	return (0);
}*/
