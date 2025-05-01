NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = src/a_main.c src/b_alloc_structs.c src/c_read_map.c src/d_validate_map.c src/e_mlx.c src/f_handler_logic.c src/g_utils.c src/z_exit.c src/cc_reachable_all.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -Lmlx -lmlx -lXext -lX11 -lm -lbsd 

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR) all

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) all

clean:
	@make -C $(MLX_DIR) clean || true
	@make -C $(LIBFT_DIR) clean || true
	rm -f $(OBJS)

fclean: clean
	@make -C $(MLX_DIR) fclean || true
	@make -C $(LIBFT_DIR) fclean || true
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 