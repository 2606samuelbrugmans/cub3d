#include "../include/cub3D.h"

void update_floor_and_ceiling(t_ray ray, t_mlx **xvar, int x)
{
	int y;
	int color;

	color = (*xvar)->data->f.rgb[0] * 65536 + (*xvar)->data->f.rgb[1] * 256 + (*xvar)->data->f.rgb[2];

	y = 0;
	while (y < ray.wall_bottom)
	{
		*(unsigned int *)((*xvar)->img.addr + y * (*xvar)->img.size_line + x * ((*xvar)->img.bpp / 8)) = color;
		y++;
	}
	color = (*xvar)->data->c.rgb[0] * 65536 + (*xvar)->data->c.rgb[1] * 256 + (*xvar)->data->c.rgb[2];

	y = ray.wall_top;
	while (y < HEIGHT - 1)
	{
		*(unsigned int *)((*xvar)->img.addr + y * (*xvar)->img.size_line + x * ((*xvar)->img.bpp / 8)) = color;
		y++;
	}
}

void 		pick_textrs(t_ray ray, int *tex)
{

	if (ray.side == 0 && ray.stepx < 0)
		(*tex) = 1;
	else if (ray.side == 0 && ray.stepx > 0)
		(*tex) = 3;
	else if (ray.side == 1 && ray.stepy < 0)
		(*tex) = 2;
	else
		(*tex) = 4;
}

void	update_texture(int x, t_ray ray,
			t_txtrs *tex, t_frame *frame)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;

	tex_x = (int)(ray.wall * tex->width);
	if ((ray.side == 0 && ray.dirx > 0)
		|| (ray.side == 1 && ray.diry < 0))
		tex_x = tex->width - tex_x - 1;
	step = 1.0 * tex->height / ray.line_height;
	tex_pos = (ray.wall_bottom - HEIGHT / 2 + ray.line_height / 2) * step;
	y = ray.wall_bottom;
	printf("bottom=%d  top=%d\n", ray.wall_bottom, ray.wall_top);
	while (y < ray.wall_top)
	{
		if (tex_pos < 0)
			tex_pos = 0;
		if (tex_pos >= tex->height)
			tex_pos = tex->height - 1;
		tex_y = ((int)tex_pos) % tex->height;
		tex_pos += step;
		ft_memcpy(frame->addr + y * frame->size_line + x * (frame->bpp / 8),
				  tex->addr + tex_y * tex->sl + tex_x * (tex->bpp / 8),
				  tex->bpp / 8);
		y++;
	}
}
