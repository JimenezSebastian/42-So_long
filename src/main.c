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