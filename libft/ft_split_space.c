/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:36:41 by mucabrin          #+#    #+#             */
/*   Updated: 2025/05/30 11:46:32 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
			count++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (count);
}

static char	*ft_wordup(char const *s)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (0);
	i = 0;
	while (s[i] && !ft_isspace(s[i]))
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static void	*ft_free(char **strs, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static	char	**ft_cpysplit(char	**split, char const *s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
		{
			split[j] = ft_wordup(&s[i]);
			if (!split[j])
				return (ft_free(split, j));
			j++;
		}
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split_space(char const *s)
{
	int		size;
	char	**split;

	if (!s)
		return (0);
	size = ft_wordcount(s);
	split = ft_calloc(sizeof(char *), size + 1);
	if (!split)
		return (0);
	return (ft_cpysplit(split, s));
}
/*
int	main(void)
{
	int		i;
	char	**split;

	split = ft_split("hello, world", 'w');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}*/
