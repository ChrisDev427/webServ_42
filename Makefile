# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axfernan <axfernan@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 11:05:14 by axfernan          #+#    #+#              #
#    Updated: 2023/11/29 11:15:46 by axfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = webserv

FLAGS =  -std=c++98 -Werror -Wextra -Wall #-g -fsanitize=address

SRC = $(wildcard srcs/*.cpp)
HDR = $(wildcard includes/*.hpp)

OBJ = $(SRC:.cpp=.o)

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

%.o: %.cpp $(HDR)
	@echo $(CURSIVE)$(GRAY) "     - Making $(NAME) object files..." $(NONE)
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -f srcs/*.o
	@echo $(CURSIVE)$(YELLOW) "     - Removing $(NAME) objects files..." $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(CURSIVE)$(YELLOW) "     - Removing $(NAME) executable..." $(NONE)

re: fclean all

.PHONY: all clean fclean re
