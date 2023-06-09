PROJ=libft
SRC=srcs
INCLUDE=includes
ROOT=$(CURDIR)
all: $(PROJ)
$(PROJ):
	gcc -c $(ROOT)/$(SRC)/*.c -o $(ROOT)/$(PROJ).o
	ar rsc $(ROOT)/$(PROJ).a $(ROOT)/$(PROJ).o
clean:
	rm -rf *.o
fclean: clean
	rm -rf *.a
re: fclean $(PROJ)