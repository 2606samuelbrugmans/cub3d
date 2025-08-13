/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:40:35 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/04 20:38:04 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	ft_ischar(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	ft_findmap(t_map *var)
{
	bool	in_map;
	int		ln_len;

	in_map = 0;
	while (var->maps[++var->map_y])
	{
		var->x = -1;
		ln_len = ft_strlen(var->maps[var->map_y]);
		while (var->maps[var->map_y][++var->x])
		{
			if (!ft_isspace(var->maps[var->map_y][var->x]))
			{
				if (!ft_ischar(var->maps[var->map_y][var->x]))
					return (ft_error_msg(ERR_MAP_CHAR, var), 0);
				if (!var->start)
					var->start = var->map_y;
				in_map = 1;
				break ;
			}
		}
		if (var->x == ln_len && in_map)
			return (var->end = var->map_y, 1);
	}
	return (var->end = var->map_y, 1);
}

static int	ft_check_aftermap(t_map *var)
{
	while (var->maps[var->map_y])
	{
		var->x = -1;
		while (var->maps[var->map_y][++var->x])
		{
			if (!ft_isspace(var->maps[var->map_y][var->x]))
				return (ft_error_msg(ERR_MAP_POS, var), 0);
		}
		var->map_y++;
	}
	return (1);
}

static int	ft_bulding_map(t_map *var)
{
	int	start;
	int	end;

	var->y = -1;
	var->x = 0;
	start = 0;
	end = 0;
	while (var->map[++var->y])
	{
		if (var->map[var->y] == '\n')
			var->x++;
		if (var->x == var->start && start == 0)
			start = var->y;
		if (var->x == var->end && end == 0)
			end = var->y;
	}
	var->f_map = ft_substr(var->map, start, end - start + 1);
	if (!var->f_map)
		return (ft_free_3d(var), ft_error_malloc(), 0);
	var->f_maps = ft_split(var->f_map, '\n');
	if (!var->f_maps)
		return (ft_free_3d(var), ft_error_malloc(), 0);
	return (1);
}

int	ft_parsecub3d(t_map *var)
{
	if (!var->map || !var->maps)
		return (ft_error_msg(ERR_MAP_NULL, var), 0);
	var->map_y = ft_parsetxtrs(var) - 1;
	ft_findmap(var);
	if (var->start == 0)
		return (ft_error_msg(ERR_NO_MAP, var), 0);
	ft_check_aftermap(var);
	ft_bulding_map(var);
	ft_parsemap(var);
	return (1);
}
