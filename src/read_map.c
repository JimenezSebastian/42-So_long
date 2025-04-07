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

char *ft_mapstr(int fd)
{
    char *mapstr;
    char *temp;
    
    temp = NULL;
    mapstr = get_next_line(fd);
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

char	*ft_temp(char *line, char *token)
{
	char	*new_line;

	new_line = NULL;
	new_line = ft_strjoin(line, token);
	free (line);
	free (token);
    if (!new_line)
        return (NULL);
    else
	    return (new_line);
}