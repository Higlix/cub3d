#include "cub.h"

int     win_init(t_game *cub)
{
    cub->mlx = mlx_init();
    if (!cub->mlx)
        return (CUBERR);
    cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, cub->title);
    if (!cub->win)
        return (CUBERR);
    return (0);
}