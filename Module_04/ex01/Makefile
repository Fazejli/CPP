# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 13:21:51 by fadzejli          #+#    #+#              #
#    Updated: 2026/04/03 14:33:04 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp \
	WrongAnimal.cpp WrongCat.cpp \
	Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) -I. $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -I. -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re