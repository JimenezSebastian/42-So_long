/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:57:12 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 13:57:13 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit(t_game *game, char *message, int state)
{
	ft_free_all(game);
	ft_putstr_fd(message, 1);
	exit(state);
}

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	ft_free_textures(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_free_map(game->map);
	free(game);
}

void	ft_free_textures(t_game *game)
{
	t_textures	*tx;

	if (!game->textures)
		return ;
	tx = game->textures;
	if (tx->wall)
		mlx_destroy_image(game->mlx, tx->wall);
	if (tx->collectible)
		mlx_destroy_image(game->mlx, tx->collectible);
	if (tx->player)
		mlx_destroy_image(game->mlx, tx->player);
	if (tx->exit)
		mlx_destroy_image(game->mlx, tx->exit);
	if (tx->floor)
		mlx_destroy_image(game->mlx, tx->floor);
	free(tx);
}

void	ft_free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->grid)
		ft_free_2d(map->grid);
	if (map->cpy1)
		ft_free_2d(map->cpy1);
	if (map->cpy2)
		ft_free_2d(map->cpy2);
	if (map->cpy_static)
		ft_free_2d(map->cpy_static);
	free(map);
}

void	ft_free_2d(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
