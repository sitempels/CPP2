# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 10:47:36 by stempels          #+#    #+#              #
#    Updated: 2025/11/24 07:46:24 by stempels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME_PROJECT = bureaucrat
NAME = $(NAME_PROJECT)
debug: NAME = $(addprefix debug_, $(NAME_PROJECT))
TYPE = EXEC
#----------------------------COMPILER------------------------------------------#
CXX = c++
debug: CXX = g++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
debug: CXXFLAGS = -g3
CPPFLAGS = $(INC_FLAG)
#
#----------------------------LINKER--------------------------------------------#
#----------------------------DEBUG---------------------------------------------#
#----------------------------HEADER--------------------------------------------#
#----------------------------SRC-----------------------------------------------#
SRC_DIR = .
#
SRCS = main Bureaucrat
#
SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(SRCS))) 
#
#----------------------------OBJ-----------------------------------------------#
OBJ_DIR = obj
OBJ = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))
#
#----------------------------LIB-----------------------------------------------#
#
LIB_DIR = .
#
INC_FLAG = -I $(LIB_DIR)
#----------------------------MISC----------------------------------------------#
#
#----------------------------RULES---------------------------------------------#
#
all: $(NAME)
#
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@
#
$(NAME): $(OBJ) 
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) $(GREEN)created !$(NC)"

run: $(NAME)
	@./$(NAME)
#
leak: debug
	@valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes --track-fds=yes ./debug_$(NAME_PROJECT)
#
vgdb: debug
	@valgrind --vgdb-error=0 --leak-check=full --show-leak-kinds=all --track-fds=yes ./debug_$(NAME_PROJECT)
#
clean:
	rm -rf $(OBJ_DIR) $(DEPENDS)
	@echo "$(NAME) $(GREEN)$@ed !$(NC)"
#
fclean: clean
	rm -rf $(NAME)
	rm -rf $(addprefix debug_, $(NAME))
	@echo "$(NAME) $(GREEN)$@ed !$(NC)"
#
ffclean: fclean
#
re: ffclean all
#
debug: $(OBJ) 
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) created !"
#
.PHONY: all clean libclean fclean ffclean re
#----------------------------TEXT----------------------------------------------#

#
#----------------------------MISC----------------------------------------------#
#
