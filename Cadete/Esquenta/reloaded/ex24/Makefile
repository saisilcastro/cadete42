#Project name
NAME=libft.a
#Compiler
CC=gcc
#Compiler flags
C_FLAGS=-Wall -Werror -Wextra
#.c files
SRC=srcs
#.h files
INCLUDE=includes
#root path
ROOT=${PWD}
#Obj creation
OBJ=$($(ROOT)/$(SRC)/*.c=.o)


all: $(NAME)
	
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(C_FLAGS) -I$(ROOT)/$(INCLUDE)/*.h -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)