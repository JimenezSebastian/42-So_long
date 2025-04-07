#include "../includes/so_long.h"

void ft_exit(t_game *game, char *message, int state)
{
    ft_free_all(game);
    ft_putstr_fd(message, 1);
    exit(state);
}

void ft_free_all(t_game *game)
{
    if (!game)
        return;
    if (game->mlx)
    {
        free(game->mlx);
        // Destruccion del bridge
    }
    if (game->window)
    {
        free(game->window);
        // Destruccion de ventanas
    }
    ft_free_textures(game->textures);
    ft_free_map(game->map);
    free(game);
}

void ft_free_textures(t_textures *textures)
{
    if (!textures)
        return;
    if (textures->wall)
        free(textures->wall);
    if (textures->collectible)
        free(textures->collectible);
    if (textures->player)
        free(textures->player);
    if (textures->exit)
        free(textures->exit);
    free(textures);
}

void ft_free_map(t_map *map)
{
    if (!map)
        return;
    if (map->grid)
        ft_free_2d(map->grid);
    if (map->cpy)
        ft_free_2d(map->cpy);
    free(map);
}

void ft_free_2d(char **grid)
{
    int i;

    if (!grid)
        return;
    i = 0;
    while (grid[i])
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

