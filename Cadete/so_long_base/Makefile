NAME = solong
INCLUDE = include
SRC = src
FLAG = -Wall -Wextra -Werror
ROOT = $(CURDIR)
ImportOf = $(CURDIR)/minilibx

all:
	$(CC) *.c ./$(SRC)/*.c -L./minilibx-linux -I./$(INCLUDE)/ -I./minilibx-linux -o $(NAME) -lmlx_Linux -lXext -lX11 -lm $(FLAG)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all