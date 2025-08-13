/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:33:56 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/19 22:59:52 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!strjoin)
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = 0;
	return (strjoin);
}
/*
int	main(void)
{
	char const	*s1;
	char const	*s2;

	s1 = NULL;
	s2 = NULL;
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
