#include "../includes/so_long.h"

int ft_validate_map(char **grid)
{
    int collectibles;
    int start;
    int exit;
    
    collectibles = 0;
    start = 0;
    exit = 0;

    if (ft_is_rectangular(grid))
        return (0);

    if (!ft_is_surrounded_by_walls(grid))
        return (0);

    ft_validate_characters(grid, &collectibles, &start, &exit);
    if (collectibles < 1 || start != 1 || exit != 1)
        return (0);
    return (1);
}

int ft_is_surrounded_by_walls(char **grid)
{
    int rows;
    int cols;
    int i;
    
    rows = 0;
    while (grid[rows] != NULL)
        rows++;
    cols = strlen(grid[0]);
    
    i = 0;
    while (i < cols)
    {
        if (grid[0][i] != '1' || grid[rows - 1][i] != '1')
            return (0);
        i++;
    }
    
    i = 0;
    while (i < rows)
    {
        if (grid[i][0] != '1' || grid[i][cols - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int ft_is_rectangular(char **grid)
{
    int len;
    int i;
    
    i = 1;
    len = strlen(grid[0]);
    while (grid[i] != NULL)
    {
        if ((int)strlen(grid[i]) != len)
            return (1);
        i++;
    }
    return (0);
}

void ft_validate_characters(char **grid, int *collectibles, int *start, int *exit)
{
    int i;
    int j;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j] != '\0')
        {
            if (grid[i][j] != '0' && grid[i][j] != '1' &&
                grid[i][j] != 'C' && grid[i][j] != 'P' && grid[i][j] != 'E')
                return (NULL);
                
            if (grid[i][j] == 'C')
                (*collectibles)++;

            if (grid[i][j] == 'P')
                (*start)++;

            if (grid[i][j] == 'E')
                (*exit)++;
            j++;
        }
        i++;
    }
}
