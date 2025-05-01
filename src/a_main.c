#include "../includes/so_long.h"

void print_array(char **arr)
{
    int i = 0;
    while (arr[i] != NULL)
    {
        printf("%s\n", arr[i]);
        i++;
    }
}
void print_str(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int	ft_close_window(void *param)
{
	t_game *game;

	game = (t_game *)param;
	ft_exit(game, "Cerrado con la X\n", 0);
	return (0);
}


void ft_play(char *ber)
{
    t_game *game;
    
    ft_alloc_structs(&game);
    ft_read_map(game, ber);
    ft_reacheble_all(game);
    ft_validate_map(game);
    ft_mlx(game);
    mlx_hook(game->window, 2, 1L << 0, ft_handle_keypress, game);
    mlx_hook(game->window, 17, 0, ft_close_window, game);
    mlx_loop(game->mlx);

}

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_exit(NULL, "Uso: ./so_long <mapa.ber>\n", 1); 
    ft_play(argv[1]);
}