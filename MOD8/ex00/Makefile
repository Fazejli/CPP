# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 10:41:53 by fadzejli          #+#    #+#              #
#    Updated: 2026/04/21 10:48:19 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
INC = easyfind.hpp

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPGLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CPPGLAGS) -c $< -o $@	

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re