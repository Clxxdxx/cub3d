NAME = cub3d
CC = cc

# Detección automática del sistema operativo
UNAME_S := $(shell uname -s)

# Configuración para macOS
ifeq ($(UNAME_S),Darwin)
CFLAGS = -Wall -Wextra -Werror -Imlx -g
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
endif

# Configuración para Linux (Ubuntu)
ifeq ($(UNAME_S),Linux)
	CFLAGS = -Wall -Wextra -Werror  -I/usr/include/readline
	LIBS = -lreadline
endif

LIBFT_DIR = src/libft
LIBFT_LIB = src/libft/libft.a
MLX_DIR = mlx
MLX_LIB = mlx/libmlx.a

COMPILE_MSG = "\033[1;32m[✓]\033[0m Compilando: \033[1;36m"
LINK_MSG = "\033[1;33m[🔗]\033[0m Enlazando ejecutable: \033[1;35m"
SUCCESS_MSG = "\n\033[1;32m┌────────────────────────────────────────┐\n\
│           ✨ COMPILACIÓN EXITOSA ✨     │\n\
│                                        │\n\
│    🎉 Proyecto listo para ejecutar 🎉  │\n\
│                                        │\n\
│         Ejecuta: \033[1;36m./cub3d\033[1;32m          │\n\
└────────────────────────────────────────┘\033[0m\n"

# Archivos fuente
SRC = src/cub3d.c src/initializer.c src/executor/executor.c src/executor/player.c src/executor/player_utils.c \
	  src/parse/read_file.c src/parse/check_ceilling_floor.c src/parse/check_textures.c \
	  src/parse/check_filename.c src/parse/utils.c src/parse/set_map_rectangular.c \
	  src/parse/check_valid_road.c src/parse/trim_map.c \
	  src/frees/free1.c  
	 
OBJ_DIR = objects
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: header $(NAME)


$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@echo $(LINK_MSG)$(NAME)'\033[0m'
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(LIBS) -o $(NAME)
	@echo $(SUCCESS_MSG)

$(MLX_LIB):
	@echo "\033[1;94m[🖥️]\033[0m Compilando MLX..."
	@make -s -C $(MLX_DIR)

$(LIBFT_LIB):
	@echo "\033[1;94m[📚]\033[0m Compilando libft..."
	@make -s -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo $(COMPILE_MSG)$<'\033[0m'
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;31m[🧹]\033[0m Limpiando archivos objeto..."
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[1;31m[🗑️]\033[0m Eliminando ejecutable..."
	@rm -f $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re header