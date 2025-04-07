#include "../includes/so_long.h"

void ft_graphic_server(t_game *game)
{
    ft_init_window(game);
    ft_load_textures(game);
    ft_render_map(game);
    mlx_hook(game->window, 17, 0, ft_handle_keypress, game);
    mlx_loop(game->mlx);
}

void ft_parse(t_game *game, char *ber)
{
    char **grid;
    
    grid = ft_read_map(ber);
    if (!grid || !grid[0])
        ft_exit(game, "Error mapa\n");
    
    if (ft_validate_map(grid) == 0)
        ft_exit(game, "Error al validar mapa", 1);
}

void ft_alloc_structs(t_game **game)
{
    *game = malloc(sizeof(t_game));
    if (!(*game))
        ft_exit(NULL, "Error: malloc game\n", 1);
    ft_init_game(*game);

    (*game)->map = malloc(sizeof(t_map));
    if (!(*game)->map)
        ft_exit(*game, "Error: malloc map\n", 1);
    ft_init_map((*game)->map);

    (*game)->textures = malloc(sizeof(t_textures));
    if (!(*game)->textures)
        ft_exit(*game, "Error: malloc textures\n", 1);
    ft_init_textures((*game)->textures);
}

int main(int argc, char **argv)
{
    t_game *game;

    if (argc == 2)
    {
        ft_alloc_structs(&game);
        ft_parse(game, argv[1]);
        ft_graphic_server(game);    
    }
    else
        ft_putstr_fd("Uso: ./so_long <mapa.ber>\n", 1);
    return (0);
}