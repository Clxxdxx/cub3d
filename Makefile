NAME = cub3d
CC = cc

# Detección automática del sistema operativo
UNAME_S := $(shell uname -s)

# Configuración para macOS
ifeq ($(UNAME_S),Darwin)
	CFLAGS = -Wall -Wextra -Werror -I/opt/homebrew/Cellar/readline/8.3.1/include -g
	LIBS = -lreadline -L/opt/homebrew/Cellar/readline/8.3.1/lib
endif

# Configuración para Linux (Ubuntu)
ifeq ($(UNAME_S),Linux)
	CFLAGS = -Wall -Wextra -Werror -I/usr/include/readline
	LIBS = -lreadline
endif

LIBFT_DIR = src/libft
LIBFT_LIB = src/libft/libft.a

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
SRC = src/cub3d.c src/parse/read_file.c src/frees/free_map.c  src/parse/check_ceilling_floor.c
	 
OBJ_DIR = objects
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: header $(NAME)


$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo $(LINK_MSG)$(NAME)'\033[0m'
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBS) -o $(NAME)
	@echo $(SUCCESS_MSG)

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