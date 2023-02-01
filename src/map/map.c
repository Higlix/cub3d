#include "cub.h"

int     map_init(char *map_file, t_map *map)
{
    if (!map_file || map_file_format(map_file))
        return (CUBERR);
    map_fill_name(map_file, map->map_file);
    if (map_fill_map(map) == CUBERR)
        return (CUBERR);
    //map_display_structure(map);
    return  (0);
}