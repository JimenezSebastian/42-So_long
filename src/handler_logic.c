#include "../includes/so_long.h"

int ft_handle_keypress(int key, t_game *game)
{
    if (key == 53)
        ft_exit(game, "Has ganado\n");
    else if (key == 13 || key == 126)
        move_player(0, game);
    else if (key == 1 || key == 125)
        move_player(1, game);
    else if (key == 0 || key == 123)
        move_player(2, game);
    else if (key == 2 || key == 124)
        move_player(3, game);
    return (0);
}

void move_player(int direction, t_game *game)
{
    int new_x;
    int new_y;
    
    new_x = game->map->player_x;
    new_y = game->map->player_y;
    
    if (direction == 0)
    {
        new_y--;
    }
    else if (direction == 1)
    {
        new_y++;
    }
    else if (direction == 2)
    {
        new_x--;
    }
    else if (direction == 3)
    {
        new_x++;
    }
    
    if (game->map->grid[new_y][new_x] != '1')
    {
        game->map->player_x = new_x;
        game->map->player_y = new_y;
        game->moves++;
        printf("Movimientos: %d\n", game->moves);
    }
    
    if (game->map->grid[new_y][new_x] == 'C')
    {
        game->map->grid[new_y][new_x] = '0';
        game->map->collectibles--;
    }
    
    check_win_condition(game);
}

void check_win_condition(t_game *game)
{
    if (game->map->collectibles == 0 &&
        game->map->grid[game->map->player_y][game->map->player_x] == 'E')
    {
        printf("¡Has ganado!\n");
        close_game(game);
    }
}
