/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:56 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 16:19:55 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mlx(t_game *game)
{
	ft_init_window(game);
	ft_load_textures(game);
	ft_render_map(game);
}

void	ft_init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_exit(game, "Error\n inicializando MiniLibX", 1);
	game->window = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "So Long");
	if (game->window == NULL)
		ft_exit(game, "Error\n creando la ventana", 1);
}

void	ft_load_textures(t_game *game)
{
	t_textures	*texture;

	texture = game->textures;
	texture->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&texture->width, &texture->height);
	if (!texture->wall)
		ft_exit(game, "Error\n cargando textura\n", 1);
	texture->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &texture->width, &texture->height);
	if (!texture->collectible)
		ft_exit(game, "Error\n cargando textura\n", 1);
	texture->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&texture->width, &texture->height);
	if (!texture->floor)
		ft_exit(game, "Error\n cargando textura\n", 1);
	texture->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&texture->width, &texture->height);
	if (!texture->player)
		ft_exit(game, "Error\n cargando textura\n", 1);
	texture->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&texture->width, &texture->height);
	if (!texture->exit)
		ft_exit(game, "Error\n cargando textura\n", 1);
}

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			ft_draw_tile(game, game->map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw_tile(t_game *game, char tile, int x, int y)
{
	void	*img;

	if (tile == '1')
		img = game->textures->wall;
	else if (tile == 'C')
		img = game->textures->collectible;
	else if (tile == 'P')
		img = game->textures->player;
	else if (tile == 'E')
		img = game->textures->exit;
	else
		img = game->textures->floor;
	mlx_put_image_to_window(game->mlx, game->window,
		img, x * TILE_SIZE, y * TILE_SIZE);
}
