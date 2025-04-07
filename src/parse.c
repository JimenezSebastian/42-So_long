#include "../includes/so_long.h"

void ft_parse(t_game *game, char *ber)
{
    char **grid;
    
    grid = ft_read_map(ber);
    if (!grid)
        ft_exit(game, "Error mapa\n");
    ft_validate_map(grid, ber);
}

char **ft_read_map(char *ber)
{
    int fd;
    char *mapstr;
    char **map;

    fd = open(ber, O_RDONLY);
    if (fd < 0)
        return (NULL);
    mapstr = ft_mapstr(fd);
    map = ft_split(mapstr, '\n');
    if  (!map)
        return (NULL);
    else 
        return (map);
}

int ft_validate_map(char **map, t_map *map_struct)
{
    int collectibles;
    int start;
    int exit;
    
    collectibles = 0;
    start = 0;
    exit = 0;
    
    if (is_rectangular(map))
        error_exit("El mapa no es rectangular.\n", map);
    validate_characters(map, &collectibles, &start, &exit);
    if (collectibles < 1 || start != 1 || exit != 1)
    {
        error_exit("El mapa no contiene elementos requeridos (C, P, E).\n", map);
    }
    if (!is_surrounded_by_walls(map))
    {
        error_exit("El mapa no está rodeado de paredes.\n", map);
    }
    map_struct->grid = map;
}

