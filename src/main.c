#include "cub.h"

int main(int argc, char **argv)
{
    if (!argv[1] || game_start(argv[1]) == CUBERR)
        ft_putstr_fd("Error\n", 1);
    return (0);
}