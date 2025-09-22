/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_alloc_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:43 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 16:19:23 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_alloc_structs(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!(*game))
		ft_exit(NULL, "Error\n malloc game\n", 1);
	ft_init_game(*game);
	(*game)->map = malloc(sizeof(t_map));
	if (!(*game)->map)
		ft_exit(*game, "Error\n malloc map\n", 1);
	ft_init_map((*game)->map);
	(*game)->textures = malloc(sizeof(t_textures));
	if (!(*game)->textures)
		ft_exit(*game, "Error\n malloc textures\n", 1);
	ft_init_textures((*game)->textures);
}

void	ft_init_game(t_game *game)
{
	if (!game)
		return ;
	game->mlx = NULL;
	game->window = NULL;
	game->map = NULL;
	game->textures = NULL;
	game->moves = 0;
}

void	ft_init_map(t_map *map)
{
	if (!map)
		return ;
	map->grid = NULL;
	map->cpy1 = NULL;
	map->cpy2 = NULL;
	map->cpy_static = NULL;
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->player_x = 0;
	map->player_y = 0;
}

void	ft_init_textures(t_textures *textures)
{
	if (!textures)
		return ;
	textures->wall = NULL;
	textures->collectible = NULL;
	textures->player = NULL;
	textures->exit = NULL;
	textures->width = 0;
	textures->height = 0;
}
