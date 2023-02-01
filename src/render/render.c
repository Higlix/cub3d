#include "cub.h"

int    render_loop(t_game *cub)
{
    render_floor(cub);
    render_ceiling(cub);
    render_ray(cub);
    if (cub->render_minimap)
        render_minimap(cub);

    mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, 0);
    int x;
    int y;

    mlx_mouse_get_pos(cub->win, &x, &y);
    if (x > cub->width / 2)
        player_rotate_right(cub);
    else if (x < cub->width / 2)
        player_rotate_left(cub);
    mlx_mouse_move(cub->win, cub->width / 2, cub->height / 2);
    mlx_destroy_image(cub->mlx, cub->data.img);
	mlx_mouse_hide();
    cub->data.img = mlx_new_image(cub->mlx, cub->width, cub->height);
    cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length, &cub->data.endian);


	if (cub->debug.mode)
		debug_outputs(cub);
    input_reg(cub);
    return (0);
}   

int     render_init(t_game *cub)
{
    mlx_loop_hook(cub->mlx, render_loop, cub);
    return (0);
}