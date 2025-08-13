/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:32:03 by mucabrin          #+#    #+#             */
/*   Updated: 2025/07/10 17:35:02 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static char	ft_check_cd(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (c);
	return (0);
}

static int	ft_check_char(t_map *var)
{
	int	check;

	check = 0;
	var->y = -1;
	while (var->f_map[++var->y])
	{
		if (var->f_map[var->y] != '1' && var->f_map[var->y] != '0'
			&& !ft_isspace(var->f_map[var->y]))
		{
			var->cd = ft_check_cd(var->f_map[var->y]);
			if (!var->cd)
				return (ft_error_msg(ERR_MAP_CHAR, var), 0);
			if (check)
				return (ft_error_msg(ERR_MAP_DOUBLE, var), 0);
			check = 1;
		}
	}
	if (!var->cd)
		return (ft_error_msg(ERR_MAP_NO_CD, var), 0);
	return (1);
}

static int	ft_valid_path(t_map *var, int x, int y)
{
	if (y < 0 || y >= ft_arraylen(var->f_maps))
		return (ft_error_msg(ERR_MAP, var), 0);
	if (var->f_maps[y][x] == '1' || var->f_maps[y][x] == 'Z')
		return (0);
	else if (var->f_maps[y][x] == '0')
		var->f_maps[y][x] = 'Z';
	else if (ft_isspace(var->f_maps[y][x]) || !var->f_maps[y][x])
		return (ft_error_msg(ERR_MAP, var), 0);
	ft_valid_path(var, x + 1, y);
	ft_valid_path(var, x - 1, y);
	ft_valid_path(var, x, y + 1);
	ft_valid_path(var, x, y - 1);
	return (1);
}

int	ft_parsemap(t_map *var)
{
	ft_check_char(var);
	ft_find_player(var);
	ft_valid_path(var, var->x, var->y);
	ft_free_strs(var->f_maps);
	var->f_maps = ft_split(var->f_map, '\n');
	if (!var->f_maps)
		return (ft_free_3d(var), ft_error_malloc(), 0);
	return (1);
}
