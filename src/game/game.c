#include "cub.h"

int game_start(char *map_file)
{
    t_game  *cub;

    cub = (t_game *) malloc(sizeof(t_game));
    if (config_init(cub) == CUBERR)
        return (CUBERR);
    cub->render_minimap = false;
    cub->cell_size = 16;
    cub->space = 0;
    cub->height = ft_atoi(config_find_value(cub, "height"));
    cub->width = ft_atoi(config_find_value(cub, "width"));
    cub->title = config_find_value(cub, "title");
    if (map_init(map_file, &cub->map) == CUBERR)
        return (CUBERR);
    if (win_init(cub) == CUBERR)
        return (CUBERR);
    if (img_init(cub) == CUBERR)
        return (CUBERR);
    if (input_init(cub) == CUBERR)
        return (CUBERR);
    if (render_init(cub) == CUBERR)
        return (CUBERR);
    if (player_init(cub) == CUBERR)
        return (CUBERR);
    cub->tex.img = mlx_xpm_file_to_image(cub->mlx, "./config/res/wood.xpm", &cub->tex_x, &cub->tex_y);
    cub->tex.addr = mlx_get_data_addr(cub->tex.img, &cub->tex.bits_per_pixel, &cub->tex.line_length, &cub->tex.endian);
    

    //mlx_mouse_hide();
    mlx_loop(cub->mlx);
    return (0);
}
