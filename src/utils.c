#include "../includes/so_long.h"

void free_map(char **map)
{
    int i;
    
    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void error_exit(char *msg, char **map)
{
    if (map != NULL)
    {
        free_map(map);
    }
    write(2, "Error\n", 6);
    write(2, msg, strlen(msg));
    exit(EXIT_FAILURE);
}
