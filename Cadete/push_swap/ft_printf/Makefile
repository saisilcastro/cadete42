NAME = libftprintf.a
INCLUDE = -I./include
VPATH = src: ./src
SRC = ft_printf.c ft_string.c ft_itoa_base.c
OBJ = ./obj/
SRCOBJ = $(SRC:%.c=${OBJ}%.o)
CFLAG = -Wall -Wextra -Werror -g3

.SILENT: $(NAME)
all: $(NAME)
$(NAME): $(SRCOBJ)
	ar -src $(NAME) $?
${OBJ}%.o : %.c
	@mkdir -p "./obj"
	@$(CC) -c $< -o $@ $(INCLUDE) $(CFLAG)
clean:
	rm -rf ./obj/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean $(NAME)
