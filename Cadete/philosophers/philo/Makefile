NAME = philo
INCLUDE = -I./
SRC = philo.c \
	  chained-of.c \
	  timer-of.c \
	  life.c \
	  main.c
OBJ = ./obj/
SRCOBJ = $(SRC:%.c=${OBJ}%.o)
CFLAG = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $^ -o $(NAME) $(CFLAG)
${OBJ}%.o : %.c
	mkdir -p ${OBJ}
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAG)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)