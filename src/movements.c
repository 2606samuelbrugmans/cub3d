#include "../include/cub3D.h"

int	check_wall(t_mlx *xvar, double x, double y)
{
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
void ft_move(char movement, t_mlx *xvar)
{
    double new_x = xvar->player.x;
    double new_y = xvar->player.y;
    double target_x, target_y;

    // calculate target position based on movement
    if (movement == 'n') // forward
    {
        target_x = new_x + xvar->player.dir_x * move_speed;
        target_y = new_y + xvar->player.dir_y * move_speed;
    }
    else if (movement == 's') // backward
    {
        target_x = new_x - xvar->player.dir_x * move_speed;
        target_y = new_y - xvar->player.dir_y * move_speed;
    }
    else if (movement == 'w') // strafe left
    {
        target_x = new_x + xvar->player.dir_y * move_speed;
        target_y = new_y - xvar->player.dir_x * move_speed;
    }
    else if (movement == 'e') // strafe right
    {
        target_x = new_x - xvar->player.dir_y * move_speed;
        target_y = new_y + xvar->player.dir_x * move_speed;
    }
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
	xvar->player.dir_x = old_dir_x * cos(angle) - xvar->player.dir_y * sin(angle);
	xvar->player.dir_y = old_dir_x * sin(angle) + xvar->player.dir_y * cos(angle);
}