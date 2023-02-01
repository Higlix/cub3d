#include "cub.h"

void    config_reset_buffer(char *buffer)
{
    int i;

    i = 0;
    while (i < 1000)
        buffer[i++] = 0;
}

int     config_read_file(char *buffer)
{
    int     i;
    int     active;
    int     fd;

    i = 0;
    active = 1;
    fd = open(CONFIG_FILE, O_RDONLY);
    config_reset_buffer(buffer);
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