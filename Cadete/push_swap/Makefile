NAME = push_swap
INCLUDE = -I./include
VPATH = src: ./src
SRC = command-of.c \
	  command-validate.c \
	  push-swap.c \
	  main.c
OBJ = ./obj/
SRCOBJ = $(SRC:%.c=${OBJ}%.o)
CFLAG = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $? $(INCLUDE) -o $(NAME) $(CFLAG)
${OBJ}%.o : %.c
	@$(CC) -c $< -o $@ $(INCLUDE) $(CFLAG)
clean:
	rm -rf ./obj/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean $(NAME)