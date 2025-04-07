#include "../includes/so_long.h"

void ft_init_window(t_game *game)
{
    game->mlx = mlx_init();
    if (game->mlx == NULL)
        ft_exit(game, "Error inicializando MiniLibX", 1);
    
    game->window = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
                                    game->map->height * TILE_SIZE, "So Long");
    if (game->window == NULL)
        ft_exit(game, "Error creando la ventana", 1);
}

void ft_load_textures(t_game *game)
{
    game->textures->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", 
                                &game->textures->width, &game->textures->height);
    if (!game->textures->wall)
        ft_exit(game, "Error cargando textura de pared (assets/wall.xpm)\n", 1);
    
    game->textures->collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", 
                                &game->textures->width, &game->textures->height);
    if (!game->textures->collectible)
        ft_exit(game, "Error cargando textura de coleccionable (assets/collectible.xpm)\n", 1);
    
    game->textures->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", 
                                &game->textures->width, &game->textures->height);
    if (!game->textures->player)
        ft_exit(game, "Error cargando textura del jugador (assets/player.xpm)\n", 1);
    
    game->textures->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", 
                                &game->textures->width, &game->textures->height);
    if (!game->textures->exit)
        ft_exit(game, "Error cargando textura de salida (assets/exit.xpm)\n", 1);
}

void ft_render_map(t_game *game)
{
    int x;
    int y;
    
    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->textures->wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->textures->collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->window, game->textures->player, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map->grid[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->textures->exit, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

