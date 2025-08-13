/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:50:21 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/29 00:50:18 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*calloc;
	size_t	i;
	size_t	len;

	i = 0;
	len = count * size;
	if (size && ((len / size) != count))
		return (NULL);
	calloc = malloc(len);
	if (!calloc)
		return (NULL);
	while (i < len)
	{
		calloc[i] = 0;
		i++;
	}
	return (calloc);
}

// int	main(void)
// {
// 	int	*tab;
// 	int	*tab2;

// 	tab = ft_calloc(15, 1);
// 	tab2 = calloc(15, 1);
// 	printf("%ld 2 : %ld\n", sizeof(tab), sizeof(tab2));
// }
