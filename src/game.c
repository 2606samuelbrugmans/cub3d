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
    
    xvar->frame_count++;
    if (xvar->frame_count % 2 == 0)
        return (0);
    init_ray(&ray, xvar->player);
    ft_raycasting(xvar, ray);
    if (xvar->keys[0])
        ft_move('n', xvar);
    if (xvar->keys[1])
        ft_move('s', xvar);
    if (xvar->keys[2])
        ft_move('w', xvar); 
    if (xvar->keys[3])
        ft_move('e', xvar);
    if (xvar->keys[4])
        ft_rotate('l', xvar); 
    if (xvar->keys[5])
        ft_rotate('r', xvar); 
    mlx_clear_window(xvar->mlx, xvar->mlx_win);
    mlx_put_image_to_window(xvar->mlx, xvar->mlx_win, xvar->img.img, 0, 0);
    return (0);
}

int key_press(int keycode, t_mlx *xvar)
{
    if (keycode == 65307) 
        ft_exit_game(xvar);
    if (keycode == 119) 
        xvar->keys[0] = 1;
    if (keycode == 115) 
        xvar->keys[1] = 1;
    if (keycode == 97) 
        xvar->keys[2] = 1;
    if (keycode == 100) 
        xvar->keys[3] = 1;
    if (keycode == 65363) 
        xvar->keys[4] = 1;
    if (keycode == 65361) 
        xvar->keys[5] = 1;
    return (0);
}

int key_release(int keycode, t_mlx *xvar)
{
    if (keycode == 119)
        xvar->keys[0] = 0;
    if (keycode == 115)
        xvar->keys[1] = 0;
    if (keycode == 97)
        xvar->keys[2] = 0;
    if (keycode == 100)
        xvar->keys[3] = 0;
    if (keycode == 65363)
        xvar->keys[4] = 0;
    if (keycode == 65361)
        xvar->keys[5] = 0;
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
    if (!xvar)
        return (0);
    init_player(&player, var);
    xvar->player = player;
    mlx_hook(xvar->mlx_win, 2, (1L << 0), key_press, xvar);
    mlx_hook(xvar->mlx_win, 3, (1L << 1), key_release, xvar);  
    mlx_hook(xvar->mlx_win, 17, 0, ft_exit_game, xvar);
    mlx_loop_hook(xvar->mlx, game_loop, xvar);
    mlx_loop(xvar->mlx);
    return (1);
}