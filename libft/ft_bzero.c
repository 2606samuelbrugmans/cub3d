/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:24:03 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/31 18:04:00 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 		char    str[50] = "GeeksForGeeks is for programming geeks.";
// 		char    str2[50] = "GeeksForGeeks is for programming geeks.";

// 		printf("\nBefore bzero(): %s\n", str);
// 		ft_bzero(str + 15, 5);
// 		printf("After bzero(): %s\n", str);
// 		bzero(str2 + 15, 5);
// 		printf("bzero = %s\n", str2);
// 		return (0);
// }