/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:46 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 16:19:33 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_read_map(t_game *game, char *ber)
{
	int		fd;
	char	*mapstr;
	char	**map;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		ft_exit(game, "Error\n Abrir .ber\n", 1);
	mapstr = ft_mapstr(fd);
	if (!mapstr)
		ft_exit(game, "Error\n Extraer mapa\n", 1);
	map = ft_split(mapstr, '\n');
	free(mapstr);
	if (!map)
		ft_exit(game, "Error\n Extraer mapa\n", 1);
	game->map->grid = map;
	ft_cpys(game);
	ft_fill_map_data(game->map, game->map->grid);
}

char	*ft_mapstr(int fd)
{
	char	*temp;
	char	*mapstr;

	mapstr = get_next_line(fd);
	if (!mapstr)
		return (NULL);
	while (1)
	{
		temp = get_next_line(fd);
		if (temp)
			mapstr = ft_temp(mapstr, temp);
		else
			break ;
	}
	close(fd);
	return (mapstr);
}

void	ft_cpys(t_game *game)
{
	game->map->cpy1 = ft_copy_grid(game->map->grid);
	if (game->map->cpy1 == NULL)
		ft_exit(game, "Error\n Copia de grid 1\n", 1);
	game->map->cpy2 = ft_copy_grid(game->map->grid);
	if (game->map->cpy2 == NULL)
		ft_exit(game, "Error\n Copia de grid 2\n", 1);
	game->map->cpy_static = ft_copy_grid(game->map->grid);
	if (game->map->cpy_static == NULL)
		ft_exit(game, "Error\n Copia de grid 3\n", 1);
}

char	**ft_copy_grid(char **grid)
{
	char	**copy;
	int		height;
	int		i;

	height = 0;
	while (grid[height])
		height++;
	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_fill_map_data(t_map *map, char **grid)
{
	int	y;
	int	x;

	while (grid[map->height])
		map->height++;
	if (map->height > 0)
		map->width = ft_strlen(grid[0]);
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
