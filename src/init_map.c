/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:42:33 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/10 14:36:44 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static t_txtrs	ft_init_txtr(void)
{
	t_txtrs	txtr;

	txtr.path = NULL;
	txtr.flag = false;
	txtr.rgb[0] = -1;
	txtr.rgb[1] = -1;
	txtr.rgb[2] = -1;
	return (txtr);
}

t_map	ft_init_t_map(void)
{
	t_map	var;

	var.map = NULL;
	var.maps = NULL;
	var.f_map = NULL;
	var.f_maps = NULL;
	var.cd = 0;
	var.start = 0;
	var.end = 0;
	var.map_y = 0;
	var.y = -1;
	var.x = -1;
	var.no = ft_init_txtr();
	var.so = ft_init_txtr();
	var.ea = ft_init_txtr();
	var.we = ft_init_txtr();
	var.c = ft_init_txtr();
	var.f = ft_init_txtr();
	return (var);
}

int	ft_readmaps(int fd, t_map *var, int lnc)
{
	char	*line;
	int		i;

	i = 0;
	var->maps = malloc(sizeof(char *) * (lnc + 1));
	line = get_next_line(fd);
	if (!line)
		ft_error_malloc();
	var->maps[i] = ft_strdup(line);
	if (!var->maps[i])
		return (free(line), ft_error_malloc(), 0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		var->maps[++i] = ft_strdup(line);
		if (!var->maps[i])
			return (free(line), ft_error_malloc(), 0);
	}
	var->maps[i + 1] = 0;
	return (1);
}

int	ft_readmap(int fd, t_map *var)
{
	char	*line;
	char	*tmp;

	var->y = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error_malloc();
	var->map = ft_strdup(line);
	if (!var->map)
		return (free(line), ft_error_malloc(), 0);
	var->y++;
	while (line)
	{
		tmp = var->map;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		var->map = ft_strjoin(tmp, line);
		if (!var->map)
			return (free(line), free(tmp), ft_error_malloc(), 0);
		free(tmp);
		var->y++;
	}
	return (var->y);
}
