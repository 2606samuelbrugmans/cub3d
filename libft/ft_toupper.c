/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:31:43 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/20 16:27:13 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	int		j;
	char	*str;
	char	ch;

	j = 0;
	str = "AbCdefghijklmnopqrstuvwxyz4656\n";
	while (str[j])
	{
		ch = str[j];
		putchar(ft_toupper(ch));
		j++;
	}
}*/
