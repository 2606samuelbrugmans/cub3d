#include "../include/cub3D.h"

void	ft_move(char movement, t_mlx *xvar)
{
	double new_x;
	double new_y;

	new_x = xvar->player.x;
	new_y = xvar->player.y;
    if (movement == 'n') // forward
    {
        new_x += xvar->player.dir_x * move_speed;
        new_y += xvar->player.dir_y * move_speed;
    }
    else if (movement == 's') // backward
    {
        new_x -= xvar->player.dir_x * move_speed;
        new_y -= xvar->player.dir_y * move_speed;
    }
    else if (movement == 'w') 
    {
        new_x += xvar->player.dir_y * move_speed; 
        new_y -= xvar->player.dir_x * move_speed;
    }
    else if (movement == 'e')
    {
        new_x -= xvar->player.dir_y * move_speed;
        new_y += xvar->player.dir_x * move_speed;
    }
	if (xvar->data->f_maps[(int)new_y][(int)new_x] != '1')
	{
		xvar->player.x = new_x;
		xvar->player.y = new_y;
	}
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