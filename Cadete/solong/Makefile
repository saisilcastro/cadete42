NAME = solong
INCLUDE = ./include
LIB = ./minilibx-linux
SRC = 	main.c \
		./src/math-of.c \
		./src/mouse-of.c \
		./src/machine.c \
		./src/place-set.c \
		./src/place-run.c \
		./src/place-destroy.c \
		./src/object-of.c \
		./src/user-init.c ./src/user-pop.c \
		./src/so_long.c \
		./src/chained-of.c ./src/chained-next.c
SRCOBJ = $(SRC:%.c=%.o)
CFLAG = -Wall -Wextra -Werror
ENGINE = -lmlx -lX11 -lXext -lm


all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) -I$(INCLUDE) -L$(LIB) $(ENGINE) -o $(NAME) $(CFLAG)
%.o: %.c
	$(CC) -c $< -o $@ -I$(INCLUDE) $(CFLAG)
clean:
	rm -rf *.o ./obj/*.o
fclean:
	rm -rf $(NAME)
re: fclean all