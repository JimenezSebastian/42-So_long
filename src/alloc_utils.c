#include "../includes/so_long.h"

void ft_init_game(t_game *game)
{
    if (!game)
        return;

    game->mlx = NULL;
    game->window = NULL;
    game->map = NULL;
    game->textures = NULL;
    game->moves = 0;
}

void ft_init_map(t_map *map)
{
    if (!map)
        return;

    map->grid = NULL;
    map->cpy = NULL;
    map->width = 0;
    map->height = 0;
    map->collectibles = 0;
    map->player_x = 0;
    map->player_y = 0;
}

void ft_init_textures(t_textures *textures)
{
    if (!textures)
        return;

    textures->wall = NULL;
    textures->collectible = NULL;
    textures->player = NULL;
    textures->exit = NULL;
    textures->width = 0;
    textures->height = 0;
}