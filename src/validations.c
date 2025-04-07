#include "../includes/so_long.h"

int is_surrounded_by_walls(char **map)
{
    int rows;
    int cols;
    int i;
    
    rows = 0;
    while (map[rows] != NULL)
    {
        rows++;
    }
    cols = strlen(map[0]);
    
    i = 0;
    while (i < cols)
    {
        if (map[0][i] != '1' || map[rows - 1][i] != '1')
        {
            return (0);
        }
        i++;
    }
    
    i = 0;
    while (i < rows)
    {
        if (map[i][0] != '1' || map[i][cols - 1] != '1')
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int is_rectangular(char **map)
{
    int len;
    int i;
    
    i = 1;
    len = strlen(map[0]);
    while (map[i] != NULL)
    {
        if ((int)strlen(map[i]) != len)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

void validate_characters(char **map, int *collectibles, int *start, int *exit)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] != '0' && map[i][j] != '1' &&
                map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E')
            {
                error_exit("Mapa contiene caracteres no válidos.\n", map);
            }
            if (map[i][j] == 'C')
            {
                (*collectibles)++;
            }
            if (map[i][j] == 'P')
            {
                (*start)++;
            }
            if (map[i][j] == 'E')
            {
                (*exit)++;
            }
            j++;
        }
        i++;
    }
}
