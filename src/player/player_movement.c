#include "cub.h"

int player_move_up(t_game *cub)
{
    if (cub->map.map[(int )cub->player.pos.y][(int )(cub->player.pos.x + cub->player.dir.x * MV_SPEED)] == '0')
        cub->player.pos.x += cub->player.dir.x * MV_SPEED;
    if (cub->map.map[(int )(cub->player.pos.y + cub->player.dir.y * MV_SPEED)][(int )cub->player.pos.x] == '0')
        cub->player.pos.y += cub->player.dir.y * MV_SPEED;
    return (0);
}

int player_move_down(t_game *cub)
{

    if (cub->map.map[(int )cub->player.pos.y][(int )(cub->player.pos.x - cub->player.dir.x * MV_SPEED)] == '0')
        cub->player.pos.x -= cub->player.dir.x * MV_SPEED;      
    if (cub->map.map[(int )(cub->player.pos.y - cub->player.dir.y * MV_SPEED)][(int )cub->player.pos.x] == '0')
        cub->player.pos.y -= cub->player.dir.y * MV_SPEED;
    return (0);
}

int player_rotate_right(t_game *cub)
{
    double old_x = cub->player.dir.x;
    cub->player.dir.x = cub->player.dir.x * cos(RO_SPEED) - cub->player.dir.y * sin(RO_SPEED);
    cub->player.dir.y = old_x * sin(RO_SPEED) + cub->player.dir.y * cos(RO_SPEED);

    double old = cub->plane.x;
    cub->plane.x = cub->plane.x * cos(RO_SPEED) - cub->plane.y * sin(RO_SPEED);
    cub->plane.y = old * sin(RO_SPEED) + cub->plane.y * cos(RO_SPEED);
    return (0);
}

int player_rotate_left(t_game *cub)
{
    double old_x = cub->player.dir.x;
    cub->player.dir.x = cub->player.dir.x * cos(-RO_SPEED) - cub->player.dir.y * sin(-RO_SPEED);
    cub->player.dir.y = old_x * sin(-RO_SPEED) + cub->player.dir.y * cos(-RO_SPEED);


    double old = cub->plane.x;
    cub->plane.x = cub->plane.x * cos(-RO_SPEED) - cub->plane.y * sin(-RO_SPEED);
    cub->plane.y = old * sin(-RO_SPEED) + cub->plane.y * cos(-RO_SPEED);
    return (0);
}

int player_move_left(t_game *cub)
{

    return (0);
}

int player_move_right(t_game *cub)
{
    //cub->player.pos.x += cub->player.dir.x;
    return (0);
}