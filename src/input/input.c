#include "cub.h"

static  int input_key_down(int key_id, t_game *cub)
{
    if (key_id == 53)
        exit(1);
    else if (key_id == KEY_W)
        cub->input.KEY_W_IS_DOWN = true;
    else if (key_id == KEY_S)
        cub->input.KEY_S_IS_DOWN = true;
    else if (key_id == KEY_A)
        cub->input.KEY_A_IS_DOWN = true;
    else if (key_id == KEY_D)
        cub->input.KEY_D_IS_DOWN = true;
    else if (key_id == KEY_Q)
        cub->input.KEY_Q_IS_DOWN = true;
    else if (key_id == KEY_E)
        cub->input.KEY_E_IS_DOWN = true;
    else if (key_id == KEY_M)
    {
        if (cub->render_minimap)
            cub->render_minimap = false;
        else
            cub->render_minimap = true;
    }
    else if (key_id == KEY_X && cub->cell_size + 1 < 24)
        cub->cell_size++;
    else if (key_id == KEY_Z && cub->cell_size - 1 > 8)
        cub->cell_size--;
    else if (key_id == KEY_SPACE)
        cub->input.KEY_SPACE_IS_DOWN = true;

    return (0);
}

static int input_key_up(int key_id, t_game *cub)
{
    if (key_id == KEY_W)
        cub->input.KEY_W_IS_DOWN = false;
    else if (key_id == KEY_S)
        cub->input.KEY_S_IS_DOWN = false;
    else if (key_id == KEY_A)
        cub->input.KEY_A_IS_DOWN = false;
    else if (key_id == KEY_D)
        cub->input.KEY_D_IS_DOWN = false;
    else if (key_id == KEY_Q)
        cub->input.KEY_Q_IS_DOWN = false;
    else if (key_id == KEY_E)
        cub->input.KEY_E_IS_DOWN = false;
    else if (key_id == KEY_SPACE)
        cub->input.KEY_SPACE_IS_DOWN = false;
    return (0);
}

int input_reg(t_game *cub)
{
    if (cub->input.KEY_W_IS_DOWN == true)
        player_move_up(cub);
    if (cub->input.KEY_S_IS_DOWN == true)
        player_move_down(cub);
    if (cub->input.KEY_A_IS_DOWN == true)
        player_move_left(cub);
    if (cub->input.KEY_D_IS_DOWN == true)
        player_move_right(cub);
    if (cub->input.KEY_Q_IS_DOWN == true)
        player_rotate_left(cub);
    if (cub->input.KEY_E_IS_DOWN == true)
        player_rotate_right(cub);
    if (cub->input.KEY_SPACE_IS_DOWN == true)
        cub->space+=3;
    else if (cub->input.KEY_SPACE_IS_DOWN == false && cub->space - 1 >= 0)
        cub->space-=3;
    return (0);
}

static int input_tmp_close()
{
    exit(1);
    return (0);
}

int     input_init(t_game *cub)
{
    cub->input.KEY_A_IS_DOWN = false;
    cub->input.KEY_S_IS_DOWN = false;
    cub->input.KEY_Q_IS_DOWN = false;
    cub->input.KEY_E_IS_DOWN = false;
    cub->input.KEY_D_IS_DOWN = false;
    cub->input.KEY_W_IS_DOWN = false;
    cub->input.KEY_SPACE_IS_DOWN = false;
    mlx_hook(cub->win, 2, 1L<<0, input_key_down, cub);
    mlx_hook(cub->win, 3, 1L<<1, input_key_up, cub);
    mlx_hook(cub->win, 17, 0, input_tmp_close, NULL);
    return (0);
}