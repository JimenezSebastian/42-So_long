#include "../includes/so_long.h"

char	*ft_temp(char *line, char *token)
{
	char	*new_line;

	new_line = NULL;
	new_line = ft_strjoin(line, token);
	if (!new_line)
		return (NULL);
	free (line);
	free (token);
	return (new_line);
}

char	*ft_token(int fd)
{
	char			*token;
	static char		buf[BUFFER_SIZE];
	static int		i = 0;
	static ssize_t	br = 0;

	token = NULL;
	if (i == br)
	{
		br = read(fd, buf, BUFFER_SIZE);
		i = 0;
		if (br == -1 || br == 0)
			return (NULL);
	}
	if (i < br)
	{
		token = malloc(2);
		if (!token)
			return (NULL);
		token[0] = buf[i];
		token[1] = '\0';
		++i;
	}
	return (token);
}

char	*ft_concate_nation(int fd)
{
	char		*token;
	char		*line;
	static int	i = 0;

	i = 0;
	line = NULL;
	token = NULL;
	while (1)
	{
		token = ft_token(fd);
		if (!token && !line)
			return (NULL);
		if (!token)
			return (line);
		if (!line)
			line = token;
		else
			line = ft_temp(line, token);
		if (line[i] == '\n')
			return (line);
		++i;
	}
}

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_concate_nation(fd);
	if (!line)
		return (NULL);
	return (line);
}

void	fill_map_data(t_map *map, char **grid)
{
	int		y;
	int		x;

	map->grid = grid;
	map->height = 0;
	map->width = 0;
	map->collectibles = 0;
	map->player_x = -1;
	map->player_y = -1;

	// Calcular alto
	while (grid[map->height])
		map->height++;

	// Calcular ancho (asumiendo todas las líneas tienen igual largo)
	if (map->height > 0)
		map->width = ft_strlen(grid[0]);

	// Copiar mapa
	map->cpy = malloc(sizeof(char *) * (map->height + 1));
	y = 0;
	while (y < map->height)
	{
		map->cpy[y] = ft_strdup(grid[y]); // reemplaza por ft_strdup si estás en 42
		y++;
	}
	map->cpy[y] = NULL;

	// Buscar jugador y contar coleccionables
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			else if (grid[y][x] == 'C')
				map->collectibles++;
			x++;
		}
		y++;
	}
}
