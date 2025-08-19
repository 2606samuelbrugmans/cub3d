/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:03:15 by mucabrin          #+#    #+#             */
/*   Updated: 2025/07/03 21:07:18 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	ft_check_rgb(char *rgb, t_map *var, char **free_rgb)
{
	int	j;
	int	digit;
	int	new_num;

	j = -1;
	digit = 0;
	new_num = 0;
	while (rgb[++j])
	{
		if (!ft_isspace(rgb[j]) && !ft_isdigit(rgb[j]))
			return (ft_free_strs(free_rgb), ft_error_msg(ERR_RGB, var), 0);
		if (ft_isdigit(rgb[j]))
		{
			if (!new_num && digit)
				return (ft_free_strs(free_rgb), ft_error_msg(ERR_RGB, var), 0);
			digit++;
			new_num = 1;
		}
		else if (ft_isspace(rgb[j]) && new_num)
			new_num = 0;
	}
	if (digit == 0 || digit > 3)
		return (ft_free_strs(free_rgb), ft_error_msg(ERR_RGB, var), 0);
	return (1);
}

static int	ft_parse_rgb(char *line, t_txtrs *txtr, t_map *var)
{
	char	**rgb;

	if (txtr->flag)
		return (ft_error_msg(ERR_DOUBLE, var), 0);
	rgb = ft_split(line, ',');
	if (!rgb)
		return (ft_free_3d(var), ft_error_malloc(), 0);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (ft_free_strs(rgb), ft_error_msg(ERR_RGB, var), 0);
	var->y = -1;
	while (rgb[++var->y])
	{
		var->x = -1;
		while (rgb[var->y][++var->x] && ft_isspace(rgb[var->y][var->x]))
			;
		if (rgb[var->y][var->x] == '0' && ft_isdigit(rgb[var->y][var->x + 1]))
			return (ft_free_strs(rgb), ft_error_msg(ERR_RGB, var), 0);
		ft_check_rgb(rgb[var->y], var, rgb);
		txtr->rgb[var->y] = ft_atoi(rgb[var->y]);
	}
	if (var->y != 3 || txtr->rgb[0] < 0 || txtr->rgb[0] > 255 || txtr->rgb[1]
		< 0 || txtr->rgb[1] > 255 || txtr->rgb[2] < 0 || txtr->rgb[2] > 255)
		return (ft_free_strs(rgb), ft_error_msg(ERR_RGB, var), 0);
	return (ft_free_strs(rgb), txtr->flag = 1, 1);
}

static int	ft_parse_path(char *line, t_txtrs *txtr, t_map *var)
{
	if (txtr->flag)
		return (ft_error_msg(ERR_DOUBLE, var), 0);
	txtr->path = ft_strtrim(line, " \t\n");
	if (!txtr->path)
		return (ft_free_3d(var), ft_error_malloc(), 0);
	txtr->flag = 1;
	
	return (1);
}

static int	ft_check_id(t_map *var, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "NO\t", 3) == 0)
		ft_parse_path(line + 3, &var->no, var);
	else if (ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "SO\t", 3) == 0)
		ft_parse_path(line + 3, &var->so, var);
	else if (ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "EA\t", 3) == 0)
		ft_parse_path(line + 3, &var->ea, var);
	else if (ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "WE\t", 3) == 0)
		ft_parse_path(line + 3, &var->we, var);
	else if (ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "F\t", 2) == 0)
		ft_parse_rgb(line + 2, &var->f, var);
	else if (ft_strncmp(line, "C ", 2) == 0
		|| ft_strncmp(line, "C\t", 2) == 0)
		ft_parse_rgb(line + 2, &var->c, var);
	else
		return (0);
	return (1);
}

int	ft_parsetxtrs(t_map *var)
{
	int	i;
	int	j;

	i = -1;
	while (var->maps[++i] && !ft_cdflags(var))
	{
		j = -1;
		while (var->maps[i][++j])
		{
			if (!ft_isspace(var->maps[i][j]))
			{
				if (!ft_check_id(var, &var->maps[i][j]))
					return (ft_error_msg(ERR_ID, var), 0);
				break ;
			}
		}
	}
	return (i);
}
