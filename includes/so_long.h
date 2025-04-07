#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

#define TILE_SIZE 64
#define BUFFER_SIZE 42

# define KEY_W      119  
# define KEY_S      115
# define KEY_A      97
# define KEY_D      100

# define ARROW_UP    65362
# define ARROW_DOWN  65364
# define ARROW_LEFT  65361
# define ARROW_RIGHT 65363

# define KEY_ESC     65307

# define UP           0
# define DOWN         1
# define LEFT         2
# define RIGHT        3


typedef struct t_textures
{
    void *wall;
    void *collectible;
    void *player;
    void *exit;
    int width;
    int height;
} t_textures;

typedef struct t_map
{
    char **grid;
    char **cpy;
    int width;
    int height; 
    int collectibles;
    int player_x;
    int player_y;
} t_map;

typedef struct t_game
{
    void *mlx;
    void *window;
    t_map *map;
    t_textures *textures;
    int moves;
} t_game;

// MODULES: PRIMERA CAPA DESPUES DEL MAIN   // Ejecutado
void ft_alloc_structs(t_game **game);
void ft_parse(t_game *game, char *ber);
void ft_graphic_server(t_game *game);

// ALLOC -  // Ejecutado
void ft_alloc_structs(t_game **game);
void ft_init_game(t_game *game);
void ft_init_map(t_map *map);
void ft_init_textures(t_textures *textures);

// PARSE 
// READ // arreglar gnl
char **ft_read_map(char *file);
char *ft_mapstr(int fd);
char	*ft_join(char *original, char *new);
// VALIDATION falta floodfill
int ft_validate_map(char **grid);
int ft_is_surrounded_by_walls(char **map);
int ft_is_rectangular(char **map);
void ft_validate_characters(char **map, int *collectibles, int *start, int *exit);

// GRAPHICS  // Ejecutado
void ft_init_window(t_game *game);
void ft_load_textures(t_game *game);
void ft_render_map(t_game *game);

// HANDLER_LOGIC - redibujar la salida. 
int ft_handle_keypress(int key, t_game *game);
void ft_move_player(int direction, t_game *game);
void ft_check_win_condition (t_game *game);

// EXIT // Ejecutado - destroy ?
void ft_free_all(t_game *game);
void ft_free_textures(t_textures *textures);
void ft_free_map(t_map *map);
void ft_free_2d(char **grid);

// extras 
char	*get_next_line(int fd);

#endif