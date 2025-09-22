/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:57:40 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 17:21:53 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define BUFFER_SIZE 42

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define KEY_ESC 65307

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef struct t_textures
{
	void		*wall;
	void		*collectible;
	void		*player;
	void		*exit;
	void		*floor;
	int			width;
	int			height;
}				t_textures;

typedef struct t_map
{
	char		**grid;
	char		**cpy1;
	char		**cpy2;
	char		**cpy_static;
	int			width;
	int			height;
	int			collectibles;
	int			player_x;
	int			player_y;
}				t_map;

typedef struct t_game
{
	void		*mlx;
	void		*window;
	int			moves;
	t_map		*map;
	t_textures	*textures;
}				t_game;

// b_alloc_structs.c
void			ft_alloc_structs(t_game **game);
void			ft_init_game(t_game *game);
void			ft_init_map(t_map *map);
void			ft_init_textures(t_textures *textures);

// c_read_map.c
void			ft_read_map(t_game *game, char *ber);
char			*ft_mapstr(int fd);
char			**ft_copy_grid(char **grid);
void			ft_fill_map_data(t_map *map, char **grid);
void			ft_cpys(t_game *game);

// d_reachable_all.c
int				ft_has_reached_exit(char **grid);
void			ft_reacheble_all(t_game *game);
void			ft_flood_fill(int x, int y, char **grid);
void			ft_flood_fill_to_exit(int x, int y, char **grid);
int				ft_has_unreachable_collectibles(char **grid);

// e_validate_map.c
void			ft_validate_map(t_game *game);
int				ft_is_rectangular(char **map);
int				ft_is_surrounded_by_walls(char **map);
int				ft_validate_characters(char **map, int *collectibles,
					int *start, int *exit);

// f_mlx.c
void			ft_mlx(t_game *game);
void			ft_init_window(t_game *game);
void			ft_load_textures(t_game *game);
void			ft_render_map(t_game *game);
void			ft_draw_tile(t_game *game, char tile, int x, int y);

// g_handler_logic.c
int				ft_handle_keypress(int key, t_game *game);
void			ft_move_player(int direction, t_game *game);
void			ft_calculate_new_position(int direction, int *new_x, int *new_y,
					t_game *game);
void			ft_check_win_condition(t_game *game);
int				ft_close_window(void *param);

// h_utils.c
char			*ft_temp(char *line, char *token);
char			*ft_token(int fd);
char			*ft_concate_nation(int fd);
char			*get_next_line(int fd);
int				ft_is_valid_filename(const char *filename);

// i_exit.c
void			ft_exit(t_game *game, char *message, int state);
void			ft_free_all(t_game *game);
void			ft_free_textures(t_game *game);
void			ft_free_map(t_map *map);
void			ft_free_2d(char **grid);

#endif