#include "../include/cub3D.h"

void init_player(t_player *player, t_map *var)
{

	player->x = (double)var->x;
	player->y = (double)var->y;
	player->dir_x = -1;
	player->dir_y = 0;
}