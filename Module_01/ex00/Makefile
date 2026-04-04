# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 11:32:01 by fadzejli          #+#    #+#              #
#    Updated: 2026/02/23 11:32:02 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombies
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
	newZombie.cpp \
	Zombie.cpp \
	randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
INC = Zombie.hpp

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