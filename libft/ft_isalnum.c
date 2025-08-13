/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:18:05 by mucabrin          #+#    #+#             */
/*   Updated: 2025/01/29 23:12:20 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 		char     c;

// 		c = "";
// 		printf("%c = %d\n", c, ft_isalnum(c));
// 		// while (c <= 127)
// 		// {
// 		// 		printf("%c = %d\n", c, ft_isalnum(c));
// 		// 		c++;
// 		// }
// 		printf("%d\n", ft_isalnum(47));
// }