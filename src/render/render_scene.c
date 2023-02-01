#include "cub.h"

int     render_floor(t_game *cub)
{
    int i;
    int j;

    i = cub->height / 2;
    while (i < cub->height)
    {
        j = 0;
        while (j < cub->width)
        {
            render_pixel_put(&cub->data, j, i, cub->map.f_color);
            j++;
        }
        i++;
    }
    return (0);
}

int     render_minimap_player(t_game *cub)
{
    double j;
    double i;

    i = (cub->player.pos.y + 0.88) * cub->cell_size;
    while (i < ((cub->player.pos.y + 0.88) * cub->cell_size) + 5)
    {
        j = (cub->player.pos.x + 0.88) * cub->cell_size;
        while (j < ((cub->player.pos.x + 0.88) * cub->cell_size) + 5)
        {
            render_pixel_put(&cub->data, j, i, rgb(0, 255, 0, 0));
            j++;
        }
        i++;
    }
    return (0);
}

int     render_minimap(t_game *cub)
{
    int i;
    int j;

    i = -1;
    render_reset_image(cub, rgb(0, 0, 0, 0));
    while (cub->map.map[++i])
    {
        j = -1;
        while (cub->map.map[i][++j])
            if (cub->map.map[i][j] == '1')
                render_cell_put(cub, j + 1, i + 1, rgb(0, 0, 0, 0));
            else if (cub->map.map[i][j] == '0')
                render_cell_put(cub, j + 1, i + 1, rgb(0, 255, 255, 255));
    }
    i = -1;
    while (++i < cub->width)
        render_line_put(cub, 
        (cub->player.pos.x + 1) * cub->cell_size, 
        (cub->player.pos.y + 1) * cub->cell_size,
        (cub->debug.ray_coll[i].x + 1) * cub->cell_size, 
        (cub->debug.ray_coll[i].y + 1) * cub->cell_size,
        rgb(0, 0, 255, 0));
    render_minimap_player(cub);
    return (0);
}

int     render_ceiling(t_game *cub)
{
    int i;
    int j;

    i = 0;
    while (i < cub->height / 2)
    {
        j = 0;
        while (j < cub->width)
        {
            render_pixel_put(&cub->data, j, i, cub->map.c_color);
            j++;
        }
        i++;
    }
    return (0);
}

int     render_wall(t_game *cub, int ws, int we, int rc)
{
    int w;
    int wc;

    w = cub->width;
    wc = rgb(0, 0, 200, 0);
    if (cub->dda.side)
        wc = rgb(0, 0, 150, 0);
    render_line_put(cub, rc, ws, rc, we, wc);
    return (0);
}