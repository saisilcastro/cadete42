NAME = solong
INCLUDE = -I./include \
		  -I./minilibx-linux
LIB = ./minilibx-linux
SRC = 	main.c \
		./src/math-of.c \
		./src/linux-keyboard.c \
		./src/mouse-of.c \
		./src/image-of.c \
		./src/pixel-of.c \
		./src/plugin/mlx-plugin.c \
		./src/plugin/mlx-keyboard-plugin.c \
		./src/plugin/mlx-mouse-plugin.c \
		./src/plugin/mlx-image-plugin.c \
		./src/plugin/mlx-destroy-plugin.c \
		./src/machine.c \
		./src/place-set.c \
		./src/place-key-get.c \
		./src/place-image-load.c \
		./src/place-map.c \
		./src/place-run.c \
		./src/place-stop.c \
		./src/place-destroy.c \
		./src/place-pop.c \
		./src/object-of.c \
		./src/user-init.c ./src/user-update.c ./src/user-pop.c \
		./src/so_long.c \
		./src/chained-of.c ./src/chained-next.c
SRCOBJ = $(SRC:%.c=%.o)
CFLAG = -Wall -Wextra -Werror
ENGINE = -lmlx -lX11 -lXext -lm


all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) $(INCLUDE) -L$(LIB) $(ENGINE) -o $(NAME) $(CFLAG)
%.o: %.c
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAG)
clean:
	rm -rf *.o ./src/*.o ./src/plugin/*.o ./obj/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all