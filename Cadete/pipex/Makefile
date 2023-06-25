NAME = pipex
SRC = main.c chained.c pipex.c pipex-file-get.c \
	  pipex-command-get.c pipex-process.c \
	  pipex-command-pop.c \
	  command-of.c
FLAG = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	$(CC) $(SRC) -o $(NAME) $(FLAG)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
