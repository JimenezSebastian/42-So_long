/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:40 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 17:34:03 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_play(char *ber)
{
	t_game	*game;

	if (ft_is_valid_filename(ber) == 0)
		ft_exit(NULL, "Error\n Extension", 1);
	ft_alloc_structs(&game);
	ft_read_map(game, ber);
	ft_validate_map(game);
	ft_reacheble_all(game);
	ft_mlx(game);
	mlx_hook(game->window, 2, 1L << 0, ft_handle_keypress, game);
	mlx_hook(game->window, 17, 0, ft_close_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_exit(NULL, "Uso: ./so_long <mapa.ber>\n", 1);
	ft_play(argv[1]);
}
