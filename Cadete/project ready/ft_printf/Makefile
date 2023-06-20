NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = ft_printf.c ft_itoa_base.c
OBJ = $(SRC:%.c=%.o)
ROOT = $(CURDIR)

all: $(NAME)
$(NAME): $(OBJ)
	ar src $(ROOT)/$(NAME) $^

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all