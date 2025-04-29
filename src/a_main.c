#include "../includes/so_long.h"

void ft_play(char *ber)
{
    t_game *game;

    ft_alloc_structs(&game); // b 
    ft_read_map(ber); // c 
    ft_validate_map(game->map); // d 
    ft_mlx(game);// e 
    mlx_hook(game->window, 17, 0, ft_handle_keypress, game); //  f handler
    mlx_loop(game->mlx);

}

int main(int argc, char **argv)
{
    if (argc != 2) // 1 = nombre programa, 2 = mapa en archivo.ber (es un puntero) Por que?.
        ft_putstr_fd("Uso: ./so_long <mapa.ber>\n", 1);//cambiar a exit. 
    ft_play(argv[1]);
}