# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 11:45:13 by fadzejli          #+#    #+#              #
#    Updated: 2026/04/20 12:00:10 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = templates
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
INC = Functions.hpp

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(FLAGS) -I. $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -I. -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY: all clean fclean re