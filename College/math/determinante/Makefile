NAME = determinant
VPATH = ./src
SRC = math-of.c main.c
INCLUDE = -I./include
LIB = ./
SRCOBJ = $(SRC:%.c=%.o)
FLAG = -Wall -Wextra -Werror -g3

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) $(INCLUDE) -L$(LIB) -o $(NAME) $(FLAG)
%.o : %.c
	$(CC) -c $< -o $@ $(INCLUDE) $(FLAG)