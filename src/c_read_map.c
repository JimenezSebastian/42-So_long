#include "../includes/so_long.h"

void ft_read_map(t_game *game, char *ber)
{
    int fd;
    char *mapstr;
    char **map;

    fd = open(ber, O_RDONLY);
    if (fd < 0)
        ft_exit(game, "Error: Abrir .ber\n", 1);
    mapstr = ft_mapstr(fd);
    if (!mapstr)
        ft_exit(game, "Error: Extraer mapa\n", 1);
    map = ft_split(mapstr, '\n');
    free(mapstr);
    if  (!map)
        ft_exit(game, "Error: Extraer mapa\n", 1);
    game->map->grid = map;
}

char *ft_mapstr(int fd)
{
    char *temp;
    char *mapstr;

    mapstr = get_next_line(fd);
    if (!mapstr)
        return(NULL);
    while (1)
    {
        temp = get_next_line(fd);
        if (temp)
            mapstr = ft_temp(mapstr, temp);
        else
            break;
    }
    close(fd);
    return (mapstr);
}

