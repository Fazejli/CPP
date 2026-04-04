# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 16:23:51 by fadzejli          #+#    #+#              #
#    Updated: 2026/03/02 03:16:09 by fadwa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Fixed.cpp Point.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) -I. $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re