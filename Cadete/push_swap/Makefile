MAKEFLAGS += --silent
NAME = push_swap
INCLUDE = -I./include -I./ft_printf/include/
VPATH = src: ./src
SRC = command-of.c \
	  command-get.c \
	  command-validate.c \
	  ft_atoi_base.c \
	  list-of.c \
	  rotate-of.c \
	  push-swap.c \
	  main.c
OBJ = ./obj/
SRCOBJ = $(SRC:%.c=${OBJ}%.o)
LIB = -L./ft_printf
CFLAG = -Wall -Wextra -Werror -g3
PRINTF = printf

all: $(PRINTF)
$(PRINTF):
	$(MAKE) -C ./ft_printf
	$(MAKE) $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $? $(LIB) -lftprintf $(INCLUDE) -o $(NAME) $(CFLAG)
${OBJ}%.o : %.c
	mkdir -p "./obj"
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAG)
clean:
	rm -rf ./obj/*.o ./ft_printf/obj/*.o
fclean: clean
	rm -rf $(NAME) ./ft_printf/*.a
re: fclean all
.PHONY: all