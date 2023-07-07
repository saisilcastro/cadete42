NAME = main
SRC = ./main.c
SRCOBJ = $(SRC:%.c=%.o)
CFLAG = -Wall -Wextra -Werror -g3

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) -o $(NAME) $(CFLAG)
%.o : %.c
	$(CC) -c $< -o $@
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean $(NAME)