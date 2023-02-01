#include "cub.h"

int render_ray(t_game *cub)
{
    int     ray_count;
    double  cam_x;

    ray_count = -1;
    while (++ray_count < cub->width)
    {
        cam_x = 2 * ray_count / (double ) cub->width - 1;
        render_dda_calc_ray_data(cub, cam_x);
        render_dda_calc_first_step(cub);
        render_dda_calc_ray_len(cub, ray_count);
        render_dda_calc_wall_height(cub, ray_count);
    }
    return (0);
}