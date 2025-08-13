/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:23:37 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/31 18:03:38 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!b)
		return (NULL);
	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 		char    str[50] = "GeeksForGeeks is for programming geeks.";
// 		// char    str2[50] = "GeeksForGeeks is for programming geeks.";

// 		printf("\nBefore memset(): %s\n", str);
// 		ft_memset(NULL, 48, -1);
// 		 printf("After memset(): %s\n", str);
// 		// printf("%s\n",memset(str2, 48, 1));
// 		return (0);
// }