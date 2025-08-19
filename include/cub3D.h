/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:58:43 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/10 14:46:30 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "./error_msg.h"
# include <fcntl.h>
# include <math.h>
# include <float.h>

# define WIDTH 1000
# define HEIGHT 900
# define rotate_speed 0.008
# define move_speed 0.01
typedef struct s_txtrs
{
	char	*path;
	bool	flag;
	int		rgb[3];
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		sl;
	int		endian;
	int		so;
}			t_txtrs;

typedef struct s_ray
{
	double	wall;
	double	fov;
	double	delta_dist_X;
	double 	delta_dist_Y;
	double	vector_size;
	double	start_x;
	double	start_y;
	double	travel_x;
	double	travel_y;
	int		hit;
	int 	side;
	int		line_height;
	double 	dirx;
	double	diry;
	double	plane_x;
	double	plane_y;
	double	player_dirX;
	double	player_dirY;
	int		stepx;
	int		stepy;
	int		wall_bottom;
	int		wall_top;
	int		mapx;
	double	wall_dist;
	int		mapy;
} t_ray;
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
} t_player;

typedef struct s_map
{
	char	*map;
	char	**maps;
	char	*f_map;
	char	**f_maps;
	char	cd;
	int		start;
	int		end;
	int		map_y;
	int		y;
	int		x;
	t_txtrs	no;
	t_txtrs	so;
	t_txtrs	ea;
	t_txtrs	we;
	t_txtrs	c;
	t_txtrs	f;
}			t_map;

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_frame;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			*keys;
	int 		frame_count;
	t_player	player;
	t_map		*data;
	t_frame		img;
}			t_mlx;


int			ft_game(t_map *var);

//[PARSING]
int			ft_parsecub3d(t_map *var);
int			ft_parsetxtrs(t_map *var);
int			ft_parsemap(t_map *var);

//[FREE]
void		ft_free_3d(t_map *var);
void		ft_error_msg(char *msg, t_map *var);
void		ft_free_mlx(t_mlx *xvar);

//[Utils]
int			ft_cdflags(t_map *var);
void		ft_find_player(t_map *var);

//[Init]
t_map		ft_init_t_map(void);
int			ft_readmaps(int fd, t_map *var, int lnc);
int			ft_readmap(int fd, t_map *var);
int			ft_init_game(t_map *var, t_mlx **xvar);

// [Raycasting]
void init_ray(t_ray *ray, t_player player);
void prepare_ray(t_ray *ray, int i);
void dda(t_ray *ray, char **map);
void draw_vertical_line(t_ray *ray);
void	update_texture(int x, t_ray ray,
			t_txtrs *tex, t_frame *frame);
void 		pick_textrs(t_ray ray, int *tex);

// [Player]
void init_player(t_player *player, t_map *var);
// [movements]
void	ft_rotate(char direction, t_mlx *xvar);
void	ft_move(char movement, t_mlx *xvar);
//// textures
void update_floor_and_ceiling(t_ray ray, t_mlx **xvar, int x);

#endif