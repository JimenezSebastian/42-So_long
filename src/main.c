#include "../includes/so_long.h"

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