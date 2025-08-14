/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:30:06 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/10 14:40:16 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	ft_exit_game(t_mlx *xvar)
{
	ft_printf_fd(1, "GAME CLOSED\n");
	ft_free_3d(xvar->data);
	ft_free_mlx(xvar);
	exit(0);
}

int ft_raycasting(t_mlx *xvar, t_ray ray)
{
    int i;
    int tex;

    i = 0;
    while (i < WIDTH) 
    {
        prepare_ray(&ray, i);
        dda(&ray, xvar->data->f_maps);
        pick_textrs(ray, &tex);
        draw_vertical_line(&ray);
		if (tex == 1)
        	update_texture(i, ray, &xvar->data->we, &(xvar->img));
		else if (tex == 2 )
        	update_texture(i, ray, &xvar->data->no, &(xvar->img));
		else if (tex == 3)
        	update_texture(i, ray, &xvar->data->ea, &(xvar->img));
		else if (tex == 4)
        	update_texture(i, ray, &xvar->data->so, &(xvar->img));
        update_floor_and_ceiling(ray, &xvar, i);
        i++;
    }
    return (0);
}

static	int game_loop(t_mlx *xvar)
{
    t_ray ray;


    init_ray(&ray, xvar->player);
    ft_raycasting(xvar, ray);
    mlx_put_image_to_window(xvar->mlx, xvar->mlx_win, xvar->img.img, 0, 0);
    return (0);
}
void    print_map(char **maps)
{
    int y = 0;

    if (!maps)
    {
        printf("Map is NULL\n");
        return;
    }
    while (maps[y])
    {
        printf("%2d: %s\n", y, maps[y]);
        y++;
    }
}
static int	key_hook(int keycode, t_mlx *xvar)
{
	if (keycode == 65307) // ESC
		ft_exit_game(xvar);
	else if (keycode == 119) // W
	 	ft_move('n', xvar);
	else if (keycode == 115) // S
	 	ft_move('s', xvar);
	else if (keycode == 97) // A
	 	ft_move('w', xvar);
	else if (keycode == 100) // D
	 	ft_move('e', xvar);
	else if (keycode == 65363) // Left arrow
	 	ft_rotate('l', xvar);
	else if (keycode == 65361) // Right arrow
	 	ft_rotate('r', xvar);
	mlx_clear_window(xvar->mlx, xvar->mlx_win);
	game_loop(xvar);
	return (0);
}

int ft_game(t_map *var)
{
    t_mlx       *xvar;
    t_player    player;

	xvar = malloc(sizeof(t_mlx));
    if (!xvar)
        return (0);
    ft_init_game(var, &xvar);
    init_player(&player, var);
	xvar->player = player;
	print_map(xvar->data->f_maps);
	game_loop(xvar);
	mlx_hook(xvar->mlx_win, 2, (1L << 0), key_hook, xvar);
    mlx_loop(xvar->mlx);
    return (1);
}