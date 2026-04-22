# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 12:14:43 by fadzejli          #+#    #+#              #
#    Updated: 2026/04/21 18:39:22 by fadwa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re