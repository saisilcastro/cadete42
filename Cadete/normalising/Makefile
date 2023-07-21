NAME = main
VPATH = src: ./
SRC = 	main.c
OBJ = ./obj/
SRCOBJ = $(SRC:%.c=${OBJ}%.o)
CFLAG = -Wall -Werror -Wextra -g3

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) -o $(NAME) $(CFLAG)
${OBJ}%.o : %.c
	$(CC) -c $< -o $@ $(CFLAG)
clean:
	rm -rf ${OBJ}*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all