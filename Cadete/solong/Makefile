NAME = solong
INCLUDE = -I./include \
		  -I./minilibx-linux
LIB = ./minilibx-linux
SRC = 	main.c \
		./src/map-of.c \
		./src/map-set.c \
		./src/map-border-validator.c \
		./src/map-flood-fill.c \
		./src/map-validate.c \
		./src/map-pop.c \
		./src/math-of.c \
		./src/linux-keyboard.c \
		./src/linux-key-number.c \
		./src/linux-key-a-to-l.c \
		./src/linux-key-m-to-x.c \
		./src/linux-key-y-to-stop.c \
		./src/linux-key-tilde-to-pgdn.c \
		./src/linux-key-left-to-pad7.c \
		./src/linux-key-pad8-to-f5.c \
		./src/linux-key-f6-to-f12.c \
		./src/mouse-of.c \
		./src/image-of.c \
		./src/pixel-of.c \
		./src/plugin/mlx-plugin.c \
		./src/plugin/mlx-plugin-keyboard.c \
		./src/plugin/mlx-plugin-mouse.c \
		./src/plugin/mlx-plugin-image.c \
		./src/plugin/mlx-plugin-draw.c \
		./src/plugin/mlx-plugin-destroy.c \
		./src/machine.c \
		./src/machine-draw.c \
		./src/place-set.c \
		./src/place-key-get.c \
		./src/place-image-load.c \
		./src/place-object.c \
		./src/place-map.c \
		./src/place-draw-bg.c \
		./src/place-draw.c \
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