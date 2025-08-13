/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:53:38 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/19 17:59:39 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1],O_WRONLY);
		ft_putchar_fd('1', fd);
	}
	return (0);
}*/
