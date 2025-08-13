/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:54:02 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/30 22:36:18 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	int		j;
// 	char	*str;
// 	char	ch;

// 	j = 0;
// 	str = "AbCdefghijklmnopqrstuvwxyz4656\n";
// 	while (str[j])
// 	{
// 		ch = str[j];
// 		putchar(ft_tolower(ch));
// 		j++;
// 	}
// }