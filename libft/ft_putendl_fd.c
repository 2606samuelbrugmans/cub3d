/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:06:18 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/19 18:45:11 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1],O_WRONLY);
		ft_putendl_fd("hello, world", fd);
	}
	return (0);
}*/
