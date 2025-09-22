/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_validate_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:53 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 17:34:11 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_validate_map(t_game *game)
{
	char	**grid;
	int		collectibles;
	int		start;
	int		exit;

	grid = game->map->grid;
	collectibles = 0;
	start = 0;
	exit = 0;
	if (ft_is_rectangular(grid))
		ft_exit(game, "Error\n Validation1\n", 1);
	if (ft_is_surrounded_by_walls(grid))
		ft_exit(game, "Error\n Validation2\n", 1);
	if (ft_validate_characters(grid, &collectibles, &start, &exit))
		ft_exit(game, "Error\n Validation3\n", 1);
	if (collectibles < 1 || start != 1 || exit != 1)
		ft_exit(game, "Error\n Validation4\n", 1);
}

int	ft_is_rectangular(char **grid)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(grid[0]);
	while (grid[i] != NULL)
	{
		if ((int)ft_strlen(grid[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_surrounded_by_walls(char **grid)
{
	int	i;
	int	rows;
	int	cols;

	i = 0;
	rows = 0;
	while (grid[rows] != NULL)
		rows++;
	cols = ft_strlen(grid[0]);
	while (i < cols)
	{
		if (grid[0][i] != '1' || grid[rows - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (grid[i][0] != '1' || grid[i][cols - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_validate_characters(char **grid, int *coll, int *start, int *exit)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] != '0' && grid[i][j] != '1' && grid[i][j] != 'C'
				&& grid[i][j] != 'P' && grid[i][j] != 'E')
				return (1);
			if (grid[i][j] == 'C')
				(*coll)++;
			if (grid[i][j] == 'P')
				(*start)++;
			if (grid[i][j] == 'E')
				(*exit)++;
			j++;
		}
		i++;
	}
	return (0);
}
