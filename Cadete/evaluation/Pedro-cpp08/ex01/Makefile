# Variables
SOURCES_DIR		:= .
OBJ_DIR			:= objects
SOURCES_FILES	:= *.cpp
OBJECTS			:= $(patsubst $(SOURCES_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SOURCES_DIR)/*.cpp))
NAME			:= span

# Commands
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g
RM			:= rm -rf

# Rules
all:	$(NAME)

$(NAME):	$(OBJECTS)
			$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o:	$(SOURCES_DIR)/%.cpp | $(OBJ_DIR)
				$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
