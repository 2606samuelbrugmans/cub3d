/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:52:16 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/10 14:36:23 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	ft_load_textures(t_mlx *xvar)
{
	xvar->data->no.img = mlx_xpm_file_to_image(xvar->mlx, xvar->data->no.path,
			&xvar->data->no.width, &xvar->data->no.height);
	if (!xvar->data->no.img)
		return (ft_free_mlx(xvar), ft_error_msg(ERR_MLX_XPM, xvar->data), 0);
	xvar->data->no.addr = mlx_get_data_addr(xvar->data->no.img,
			&xvar->data->no.bpp, &xvar->data->no.sl, &xvar->data->no.endian);
	xvar->data->so.img = mlx_xpm_file_to_image(xvar->mlx, xvar->data->so.path,
			&xvar->data->so.width, &xvar->data->so.height);
	if (!xvar->data->so.img)
		return (ft_free_mlx(xvar), ft_error_msg(ERR_MLX_XPM, xvar->data), 0);
	xvar->data->so.addr = mlx_get_data_addr(xvar->data->so.img,
			&xvar->data->so.bpp, &xvar->data->so.sl, &xvar->data->so.endian);
	xvar->data->ea.img = mlx_xpm_file_to_image(xvar->mlx, xvar->data->ea.path,
			&xvar->data->ea.width, &xvar->data->ea.height);
	if (!xvar->data->ea.img)
		return (ft_free_mlx(xvar), ft_error_msg(ERR_MLX_XPM, xvar->data), 0);
	xvar->data->ea.addr = mlx_get_data_addr(xvar->data->ea.img,
			&xvar->data->ea.bpp, &xvar->data->ea.sl, &xvar->data->ea.endian);
	xvar->data->we.img = mlx_xpm_file_to_image(xvar->mlx, xvar->data->we.path,
			&xvar->data->we.width, &xvar->data->we.height);
	if (!xvar->data->we.img)
		return (ft_free_mlx(xvar), ft_error_msg(ERR_MLX_XPM, xvar->data), 0);
	xvar->data->we.addr = mlx_get_data_addr(xvar->data->we.img,
			&xvar->data->we.bpp, &xvar->data->we.sl, &xvar->data->we.endian);
	return (1);
}

int ft_init_game(t_map *var, t_mlx **xvar)
{
	(*xvar)->data = var;
	(*xvar)->mlx = mlx_init();
	if (!(*xvar)->mlx)
		return (ft_error_msg(ERR_MLX_INIT, var), 0);
	(*xvar)->mlx_win = mlx_new_window((*xvar)->mlx, WIDTH, HEIGHT, "cub3D");
	if (!(*xvar)->mlx_win)
		return (ft_free_mlx(*xvar), ft_error_msg(ERR_MLX_WIN, var), 0);
	(*xvar)->img.img = mlx_new_image((*xvar)->mlx, WIDTH, HEIGHT);
	if (!(*xvar)->img.img)
		return (ft_free_mlx(*xvar), ft_error_msg(ERR_MLX_IMG, var), 0);
	(*xvar)->img.addr = mlx_get_data_addr((*xvar)->img.img, &(*xvar)->img.bpp,
			&(*xvar)->img.size_line, &(*xvar)->img.endian);
	(*xvar)->keys = calloc(6, sizeof(int));
	(*xvar)->frame_count = 0;
	(*xvar)->data->so.so = 1;
	(*xvar)->data->no.so = 0;
	(*xvar)->data->we.so = 0;
	(*xvar)->data->ea.so = 0;
	if (!(*xvar)->keys)
		return (0);
	ft_load_textures(*xvar);
	return (1);
}
