/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:38:06 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/10 14:46:15 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_cdflags(t_map *var)
{
	if (var->no.flag && var->so.flag && var->ea.flag && var->we.flag
		&& var->c.flag && var->f.flag)
		return (1);
	return (0);
}

void	ft_find_player(t_map *var)
{
	var->y = 0;
	while (var->f_maps[var->y])
	{
		var->x = 0;
		while (var->f_maps[var->y][var->x])
		{
			if (var->f_maps[var->y][var->x] == var->cd)
				return ;
			var->x++;
		}
		var->y++;
	}
}
