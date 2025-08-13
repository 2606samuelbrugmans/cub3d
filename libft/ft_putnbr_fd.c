/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:49:13 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/19 19:46:07 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n *= -1, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		n += 48;
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1],O_WRONLY);
		ft_putnbr_fd(2147483647, fd);
	}
	return (0);
}*/
