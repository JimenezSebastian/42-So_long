/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_reachable_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:50 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 16:19:43 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_reacheble_all(t_game *game)
{
	char	**cpy1;
	char	**cpy2;
	t_map	*map;

	map = game->map;
	cpy1 = map->cpy1;
	cpy2 = map->cpy2;
	ft_flood_fill(map->player_x, map->player_y, cpy1);
	if (ft_has_unreachable_collectibles(cpy1))
		ft_exit(game, "Error\n Collectible no reacheble\n", 1);
	ft_flood_fill_to_exit(map->player_x, map->player_y, cpy2);
	if (!ft_has_reached_exit(cpy2))
		ft_exit(game, "Error\n Exit no reacheble\n", 1);
}

void	ft_flood_fill(int x, int y, char **grid)
{
	if (grid[y][x] != '0' && grid[y][x] != 'C' && grid[y][x] != 'P')
		return ;
	grid[y][x] = 'F';
	ft_flood_fill(x + 1, y, grid);
	ft_flood_fill(x - 1, y, grid);
	ft_flood_fill(x, y + 1, grid);
	ft_flood_fill(x, y - 1, grid);
}

int	ft_has_unreachable_collectibles(char **grid)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_flood_fill_to_exit(int x, int y, char **grid)
{
	if (grid[y][x] == '1' || grid[y][x] == 'F')
		return ;
	grid[y][x] = 'F';
	ft_flood_fill_to_exit(x + 1, y, grid);
	ft_flood_fill_to_exit(x - 1, y, grid);
	ft_flood_fill_to_exit(x, y + 1, grid);
	ft_flood_fill_to_exit(x, y - 1, grid);
}

int	ft_has_reached_exit(char **grid)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
