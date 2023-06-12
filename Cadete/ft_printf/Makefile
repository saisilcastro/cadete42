NAME = ft_printf.a
FLAG = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	cc main.c ft_printf.c ft_itoa_base.c -o main $(FLAG)
clean:
	rm -rf *.o
fclean:
	rm -rf *.a
re: clean fclean all