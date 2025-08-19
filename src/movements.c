#include "../include/cub3D.h"

int	check_wall(t_mlx *xvar, double x, double y)
{
    if (!xvar || !xvar->data || !xvar->data->f_maps)
		return (1);
	return (xvar->data->f_maps[(int)y][(int)x] == '1');
}

int	check_collision(t_mlx *xvar, double new_x, double new_y)
{
	if (check_wall(xvar, new_x + 0.3, new_y))
		return (1);
	if (check_wall(xvar, new_x - 0.3, new_y))
		return (1);
	if (check_wall(xvar, new_x, new_y + 0.3))
		return (1);
	if (check_wall(xvar, new_x, new_y - 0.3))
		return (1);
	if (check_wall(xvar, new_x, xvar->player.y))
		return (1);
	if (check_wall(xvar, xvar->player.x, new_y))
		return (1);
	return (0);
}

static void	get_movement_offset(char movement, t_player player,
				double *target_x, double *target_y)
{
	if (movement == 'n')
	{
		*target_x = player.dir_x * move_speed;
		*target_y = player.dir_y * move_speed;
	}
	else if (movement == 's')
	{
		*target_x = -player.dir_x * move_speed;
		*target_y = -player.dir_y * move_speed;
	}
	else if (movement == 'w')
	{
		*target_x = player.dir_y * move_speed;
		*target_y = -player.dir_x * move_speed;
	}
	else if (movement == 'e')
	{
		*target_x = -player.dir_y * move_speed;
		*target_y = player.dir_x * move_speed;
	}
	else
	{
		*target_x = 0;
		*target_y = 0;
	}
}

void	ft_move(char movement, t_mlx *xvar)
{
	double	new_x;
	double	new_y;
	double	target_x;
	double	target_y;

	new_x = xvar->player.x;
	new_y = xvar->player.y;
	get_movement_offset(movement, xvar->player, &target_x, &target_y);
	target_x += new_x;
	target_y += new_y;
	if (!check_collision(xvar, target_x, xvar->player.y))
		xvar->player.x = target_x;
	if (!check_collision(xvar, xvar->player.x, target_y))
		xvar->player.y = target_y;
}

void	ft_rotate(char direction, t_mlx *xvar)
{
	double	old_dir_x;
	double	angle;

	old_dir_x = xvar->player.dir_x;
	if (direction == 'r')
		angle = -rotate_speed;
	else
		angle = rotate_speed;
	xvar->player.dir_x = old_dir_x
        * cos(angle) - xvar->player.dir_y * sin(angle);
	xvar->player.dir_y = old_dir_x
        * sin(angle) + xvar->player.dir_y * cos(angle);
}