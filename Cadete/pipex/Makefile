NAME = pipex
SRC = main.c chained.c pipex.c pipex-file-get.c \
	  pipex-command-get.c pipex-environment-get.c \
	  pipex-show.c pipex-process.c pipex-execute.c \
	  process-run.c pipex-command-pop.c \
	  path_create.c command-of.c \
	  ft_strdup.c ft_strlen.c
FLAG = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	$(CC) $(SRC) -o $(NAME) $(FLAG)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
