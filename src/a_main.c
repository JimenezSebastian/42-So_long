#include "../includes/so_long.h"

void ft_play(char *ber)
{
    t_game *game;

    ft_alloc_structs(&game);
    ft_read_map(game, ber);
    ft_validate_map(game->map); // pasar game para liberacion atomica..
    ft_mlx(game);
    mlx_hook(game->window, 17, 0, ft_handle_keypress, game);
    mlx_loop(game->mlx);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_exit(NULL, "Uso: ./so_long <mapa.ber>\n", 1); 
    ft_play(argv[1]);
}