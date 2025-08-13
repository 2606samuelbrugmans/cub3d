/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:02:03 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/05 23:08:11 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_free_3d(t_map *var)
{
	free(var->map);
	ft_free_strs(var->maps);
	free(var->f_map);
	ft_free_strs(var->f_maps);
	free(var->no.path);
	free(var->so.path);
	free(var->ea.path);
	free(var->we.path);
}

void	ft_error_msg(char *msg, t_map *var)
{
	ft_free_3d(var);
	ft_printf_fd(2, msg);
	exit(EXIT_FAILURE);
}

void	ft_free_mlx(t_mlx *xvar)
{
	if (xvar->img.img)
		mlx_destroy_image(xvar->mlx, xvar->img.img);
	if (xvar->data->no.img)
		mlx_destroy_image(xvar->mlx, xvar->data->no.img);
	if (xvar->data->so.img)
		mlx_destroy_image(xvar->mlx, xvar->data->so.img);
	if (xvar->data->ea.img)
		mlx_destroy_image(xvar->mlx, xvar->data->ea.img);
	if (xvar->data->we.img)
		mlx_destroy_image(xvar->mlx, xvar->data->we.img);
	if (xvar->mlx_win)
		mlx_destroy_window(xvar->mlx, xvar->mlx_win);
	mlx_destroy_display(xvar->mlx);
	free(xvar->mlx);
}
