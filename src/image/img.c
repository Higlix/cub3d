#include "cub.h"

int	    rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int     img_init(t_game *cub)
{
    cub->data.img = mlx_new_image(cub->mlx, cub->width, cub->height);
    if (!cub->data.img)
        return (CUBERR);
    cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
    &cub->data.line_length, &cub->data.endian);
    if (!cub->data.addr)
        return (CUBERR);
    return (0);
}