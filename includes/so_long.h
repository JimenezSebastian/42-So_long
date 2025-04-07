#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

#define TILE_SIZE 64
#define BUFFER_SIZE 42

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

// MODULES PRIMERA CAPA DESPUES DEL MAIN 
void ft_alloc_structs(t_game **game);
void ft_parse(t_game *game, char *ber);
void ft_graphic_server(t_game *game);

// ALLOC
void ft_alloc_structs(t_game **game);
void ft_init_game(t_game *game);
void ft_init_map(t_map *map);
void ft_init_textures(t_textures *textures);

// PARSE 

//GRAPHIC SERVER


// READ MAP
char **ft_read_map(char *file);
char	*get_next_line(int fd);

// VALIDATION
int ft_validate_map(char **map, t_map *map_struct);
int is_surrounded_by_walls(char **map);
int is_rectangular(char **map);
void validate_characters(char **map, int *collectibles, int *start, int *exit);
// PARSE UTILS


// GRAPHICS
void ft_init_window(t_game *game);
void ft_load_textures(t_game *game);
void ft_render_map(t_game *game);

// HANDLER logic
int ft_handle_keypress(int key, t_game *game);
void move_player(int direction, t_game *game);
void check_win_condition(t_game *game);

// EXIT 
void ft_free_all(t_game *game);
void ft_free_textures(t_textures *textures);
void ft_free_map(t_map *map);
void ft_free_2d(char **grid);

#endif