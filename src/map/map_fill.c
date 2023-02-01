#include "cub.h"

static int map_reset_buffer(char *buffer)
{
    int i;

    i = -1;
    while (++i < 10000)
        buffer[i] = '\0';
    return (0);
}

static int map_extract(char *buffer, char *file_name)
{
    int fd;
    int active;
    int i;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (CUBERR);
    active = 1;
    i = 0;
    map_reset_buffer(buffer);
    while (active)
    {
        active = read(fd, &buffer[i], 1);
        if (active == -1)
        {
            close(fd);
            return (CUBERR);
        }
        i++;
    }
    return (0);
}

static int map_color(t_map *map, char *buffer)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            count++;
        i++;
        if (count == 4)
            break ;
    }
    if (map_floor_color(map, &buffer[i], &i) == CUBERR)
        return (CUBERR);
    if (map_ceiling_color(map, &buffer[i]) == CUBERR)
        return (CUBERR);

    return (0);
}

int     map_fill_map(t_map *map)
{
    char    buffer[10000];
    int     i;
    int     count;

    i = 0;
    count = 0;
    if (map_extract(buffer, map->map_file) == CUBERR)
        return (CUBERR);
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            count++;
        if (count == 6)
            break ;
        i++;
    }
    i++;
    map->map = ft_split(&buffer[i], '\n');
    if (map_color(map, buffer) == CUBERR)
        //free map
        return (CUBERR);
    return (0);
}