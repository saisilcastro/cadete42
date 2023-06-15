# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 20:04:22 by rapdos-s          #+#    #+#              #
#    Updated: 2023/06/14 20:42:12 by rapdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = a.out

SRC		 = ${wildcard *.cpp}

OBJ		 = ${SRC:.cpp=.o}

DEP		 = ${OBJ:.o=.d}

CXX		 = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

DEPFLAGS = -MMD -MF

VALGRIND = valgrind

VALFLAGS = --quiet \
		   --show-error-list=yes \
		   --show-leak-kinds=all \
		   --track-origins=yes \
		   --error-exitcode=42 \
		   --exit-on-first-error=yes

DEL		 = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	${DEL} ${OBJ} ${DEP}

fclean: clean
	${DEL} ${NAME}

re: fclean all

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@ ${DEPFLAGS} ${@:.o=.d}

valgrind: ${NAME}
	${VALGRIND} ${VALFLAGS} ./${NAME}

-include ${DEP}

.PHONY: all clean fclean re valgrind
