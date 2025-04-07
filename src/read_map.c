#include "../includes/so_long.h"

char **ft_read_map(char *ber)
{
    int fd;
    char *mapstr;
    char **map;

    fd = open(ber, O_RDONLY);
    if (fd < 0)
        return (NULL); // liberacion atras
    mapstr = ft_mapstr(fd);
    if (!mapstr)
        return (NULL); // liberacion atras
    map = ft_split(mapstr, '\n');
    free(mapstr);
    if  (!map)
        return (NULL); // liberacion atras
    return (map);
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