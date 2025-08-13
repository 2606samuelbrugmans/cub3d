/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:57:16 by mucabrin          #+#    #+#             */
/*   Updated: 2025/07/14 16:26:57 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		lnc;
	t_map	var;

	if (argc != 2)
		return (ft_printf_fd(2, "Error: Wrong number of arguments\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error"), 1);
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") != 0)
		return (ft_printf_fd(2, "Error: Wrong file extension\n"), close(fd), 1);
	var = ft_init_t_map();
	lnc = ft_readmap(fd, &var);
	close(fd);
	fd2 = open(argv[1], O_RDONLY);
	if (fd2 == -1)
		return (perror("Error"), 1);
	ft_readmaps(fd2, &var, lnc);
	close(fd2);
	ft_parsecub3d(&var);
	ft_game(&var);
	return (0);
}
