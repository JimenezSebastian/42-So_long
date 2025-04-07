#include "../includes/so_long.h"

int	ft_handle_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		ft_exit(game, "Salida con ESC\n");
	else if (key == KEY_W || key == ARROW_UP)
		ft_move_player(UP, game);
	else if (key == KEY_S || key == ARROW_DOWN)
		ft_move_player(DOWN, game);
	else if (key == KEY_A || key == ARROW_LEFT)
		ft_move_player(LEFT, game);
	else if (key == KEY_D || key == ARROW_RIGHT)
		ft_move_player(RIGHT, game);
	return (0);
}

void	ft_move_player(int direction, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x;
	new_y = game->map->player_y;

	// Aplicar desplazamiento según la dirección en un pseudo mov 
	if (direction == UP)
		new_y--;
	else if (direction == DOWN)
		new_y++;
	else if (direction == LEFT)
		new_x--;
	else if (direction == RIGHT)
		new_x++;

	// Validar que el nuevo movimiento no sea hacia una pared
	if (game->map->grid[new_y][new_x] == '1')
		return;

	// Si hay un coleccionable, lo recoge
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->map->grid[new_y][new_x] = '0';
		game->map->collectibles--;
	}

	// Actualiza la posición del jugador en la struct map para la logica del juego.
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->moves++;

    ft_render_map(game);
	// Comprueba si el jugador ha ganado
	ft_check_win_condition(game);
    
}


void ft_check_win_condition(t_game *game)
{
    t_map *map = game->map;
    
    if (map->collectibles == 0 &&
        map->cpy[map->player_y][map->player_x] == 'E')
        ft_exit(game, "Has ganado!\n");
}