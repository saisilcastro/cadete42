PROJ=ft_display_file
SRC=src
INCLUDE=include
ROOT=$(CURDIR)
all:
	cc *.c $(ROOT)/$(SRC)/*.c -I$(ROOT)/$(INCLUDE)/*.h -o $(PROJ) -Wall -Wextra -Werror
clean:
	rm -rf *.o
fclean: clean
	rm -rf *.a