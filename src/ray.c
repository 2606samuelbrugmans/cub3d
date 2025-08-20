#include "../include/cub3D.h"

void	init_ray(t_ray *ray, t_player player)
{
	ray->fov = 66; 
	ray->delta_dist_X = 0.0; 
	ray->delta_dist_Y = 0.0;
	ray->vector_size = 0.0; 
	ray->start_x = player.x; 
	ray->start_y = player.y;
	ray->travel_x = 0.0; 
	ray->travel_y = 0.0;
	ray->hit = 0; 
	ray->side = 0; 
	ray->dirx = 0; 
	ray->diry = 0; 
	ray->player_dirX = player.dir_x; 
	ray->player_dirY = player.dir_y;
	ray->plane_x = -0.66 * ray->player_dirY; 
	ray->plane_y = 0.66 * ray->player_dirX; 
	ray->stepx = 0;
	ray->stepy = 0;
}
void first_step_ray(t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->travel_x = (ray->start_x - ray->mapx) * ray->delta_dist_X;
	}
	else
	{
		ray->stepx = 1;
		ray->travel_x = (ray->mapx + 1.0 - ray->start_x) * ray->delta_dist_X;
	}

	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->travel_y = (ray->start_y - ray->mapy) * ray->delta_dist_Y;
	}
	else
	{
		ray->stepy = 1;
		ray->travel_y = (ray->mapy + 1.0 - ray->start_y) * ray->delta_dist_Y;
	}
	if (ray->travel_x == 0)
		ray->travel_x = 0.0001;
	if (ray->travel_y == 0)
		ray->travel_y = 0.0001;
}

void prepare_ray(t_ray *ray, int i)
{
	double camerax;

	camerax = (2.0 * i / (WIDTH)) - 1;
	ray->dirx = ray->player_dirX + ray->plane_x * camerax;
	ray->diry = ray->player_dirY + ray->plane_y * camerax;
	if (fabs(ray->dirx) < 1e-6)
	{
		if (ray->dirx < 0)
			ray->dirx = -1e-6;
		else
			ray->dirx = 1e-6;
	}
	if (fabs(ray->diry) < 1e-6)
	{
		if (ray->diry < 0)
			ray->diry = -1e-6;
		else
			ray->diry = 1e-6;
	}
	ray->delta_dist_X = fabs(1.0 / ray->dirx);
	ray->delta_dist_Y = fabs(1.0 / ray->diry);
	ray->mapx = (int)ray->start_x;
	ray->mapy = (int)ray->start_y;
	ray->hit = 0;
	first_step_ray(ray);
}
void dda(t_ray *ray, char **map)
{
	while (!ray->hit)
	{
		if (ray->travel_x < ray->travel_y)
	   	{
			ray->travel_x += ray->delta_dist_X;
			ray->mapx += ray->stepx;
			ray->side = 0;
	   	}
		else
	   	{
			ray->travel_y += ray->delta_dist_Y;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (ray->mapx < 0 || ray->mapy < 0 || map[ray->mapy] == NULL)
		{
			ray->hit = 1;
			break ;
		}
	   if (map[ray->mapy][ray->mapx] != 'S' &&
				map[ray->mapy][ray->mapx] > '0')
			ray->hit = 1;
	}
}

void	draw_vertical_line(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->mapx - ray->start_x
				+ (1 - ray->stepx) / 2) / ray->dirx;
	else
		ray->wall_dist = (ray->mapy - ray->start_y
				+ (1 - ray->stepy) / 2) / ray->diry;
	if (ray->wall_dist <= 0)
		ray->wall_dist = 0.0001;
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->wall_bottom = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->wall_bottom < 0)
		ray->wall_bottom = 0;
	ray->wall_top = ray->line_height / 2 + HEIGHT / 2;
	if (ray->wall_top >= HEIGHT)
		ray->wall_top = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall = ray->start_y + ray->wall_dist * ray->diry;
	else
		ray->wall = ray->start_x + ray->wall_dist * ray->dirx;
	ray->wall -= floor(ray->wall);
}
