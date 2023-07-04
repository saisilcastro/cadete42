NAME = start
INCLUDE = -I./minilibx-linux
LIB = ./minilibx-linux
SRC = main.c
SRCOBJ = $(SRC:%.c=%.o)

CFLAG = -Wall -Wextra -Werror
ENGINE = -lmlx -lX11 -lXext -lm

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) $(INCLUDE) -L$(LIB) $(ENGINE) -o $(NAME) $(CFLAG)
%.o: %.c
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAG)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all