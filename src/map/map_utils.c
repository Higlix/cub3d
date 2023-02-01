#include "cub.h"

int     map_fill_name(char *file, char map_file[96])
{
    int i;
    int file_name_size;

    i = 0;
    file_name_size = ft_strlen(file);
    while (i < 96)
    {
        if (i < file_name_size)
            map_file[i] = file[i];
        else
            map_file[i] = '\0';
        i++;
    }
    return (0);
}

int     map_floor_color(t_map *map, char *buffer, int *index)
{
    int i;
    int r;
    int g;
    int b;

    i = 0;
    if (buffer[i] == 'F')
    {
        while (!(buffer[i] >= '0' && buffer[i] <= '9'))
            i++;
        r = ft_atoi(&buffer[i]);
        while (buffer[i] != ',')
            i++;
        i++;
        g = ft_atoi(&buffer[i]);
        while (buffer[i] != ',')
            i++;
        i++;
        b = ft_atoi(&buffer[i]);
        map->f_color = rgb(0, r, g, b);
        while (buffer[i] != '\n')
            i++;
        i++;
    }
    else
        return (CUBERR);
    *index = i + *index;
    return (0);
}

int     map_ceiling_color(t_map *map, char *buffer)
{
    int i;
    int r;
    int g;
    int b;

    i = 0;
    if (buffer[i] == 'C')
    {
        while (!(buffer[i] >= '0' && buffer[i] <= '9'))
            i++;
        r = ft_atoi(&buffer[i]);
        while (buffer[i] != ',')
            i++;
        i++;
        g = ft_atoi(&buffer[i]);
        while (buffer[i] != ',')
            i++;
        i++;
        b = ft_atoi(&buffer[i]);
        map->c_color = rgb(0, r, g, b);
        while (buffer[i] != '\n')
            i++;
        i++;
    }
    else
        return (CUBERR);
    return (0);
}

void    map_display_structure(t_map *map)
{
    ft_println(map->map_file);
}