# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/07 14:00:41 by fadzejli          #+#    #+#              #
#    Updated: 2026/04/17 17:29:07 by fadwa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -I. $(OBJ) -o $(NAME) 

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
