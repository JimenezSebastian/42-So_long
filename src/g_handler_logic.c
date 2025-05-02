/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_handler_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:57:03 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 14:03:23 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_handle_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		ft_exit(game, "Salida con ESC\n", 1);
	else if (key == KEY_W || key == ARROW_UP)
		ft_move_player(UP, game);
	else if (key == KEY_S || key == ARROW_DOWN)
		ft_move_player(DOWN, game);
	else if (key == KEY_A || key == ARROW_LEFT)
		ft_move_player(LEFT, game);
	else if (key == KEY_D || key == ARROW_RIGHT)
		ft_move_player(RIGHT, game);
	ft_render_map(game);
	ft_check_win_condition(game);
	return (0);
}

void	ft_move_player(int direction, t_game *game)
{
	int	new_x;
	int	new_y;

	ft_calculate_new_position(direction, &new_x, &new_y, game);
	if (game->map->grid[new_y][new_x] == '1'
		|| (game->map->grid[new_y][new_x] == 'E'
			&& game->map->collectibles != 0))
		return ;
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->map->grid[new_y][new_x] = '0';
		game->map->collectibles--;
	}
	game->map->grid[game->map->player_y][game->map->player_x] = '0';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	game->moves++;
	ft_putstr_fd("Movimientos: ", 1);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
}

void	ft_calculate_new_position(int direction, int *new_x, int *new_y,
		t_game *game)
{
	*new_x = game->map->player_x;
	*new_y = game->map->player_y;
	if (direction == UP)
		(*new_y)--;
	else if (direction == DOWN)
		(*new_y)++;
	else if (direction == LEFT)
		(*new_x)--;
	else if (direction == RIGHT)
		(*new_x)++;
}

int	ft_close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_exit(game, "Cerrado con la X\n", 0);
	return (0);
}

void	ft_check_win_condition(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (map->collectibles == 0
		&& map->cpy_static[map->player_y][map->player_x] == 'E')
		ft_exit(game, "Has ganado!\n", 1);
}
