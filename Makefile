NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/game_logic.c src/graphics.c src/events.c src/map.c src/utils.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
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

.PHONY all clean fclean re 