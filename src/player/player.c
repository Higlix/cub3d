#include "cub.h"

static int player_ori(t_game *cub, int x, int y, char ori)
{
	cub->player.pos.x = x;
	cub->player.pos.y = y;
	cub->map.map[y][x] = '0';
	if (ori == 'N')
	{

	}
	else if (ori == 'S')
	{

	}
	else if (ori == 'W')
	{

	}
	else if (ori == 'E')
	{

	}
	return (0);
}

static int player_find_position(t_game *cub)
{
    char    **map;
	int		cor[2];
    int     width;

    cor[X] = 0;
    cor[Y] = 0;
    width = 0;
    map = cub->map.map;
	cub->player.pos.x = -1;
    while (map[cor[Y]])
    {
        cor[X] = 0;
        while (map[cor[Y]][cor[X]])
        {
            if (map[cor[Y]][cor[X]] == 'N' || map[cor[Y]][cor[X]] == 'S'
			|| map[cor[Y]][cor[X]] == 'W' || map[cor[Y]][cor[X]] == 'E')
                player_ori(cub, cor[X], cor[Y], map[cor[Y]][cor[X]]);
            cor[X]++;
        }
        if (cor[X] > width)
            width = cor[X];
        cor[Y]++;
    }
	if (cub->player.pos.x == -1)
		return (CUBERR);
    cub->map.height = cor[Y];
    cub->map.width = width;
    return (0);
}

int player_init(t_game *cub)
{
    cub->player.dir.x = -1;
    cub->player.dir.y = 0;
    cub->plane.x = 0;
    cub->plane.y = 0.66;
    if (player_find_position(cub) == CUBERR)
		return (CUBERR);
    return (0);
}