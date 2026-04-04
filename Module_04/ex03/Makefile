# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/03 14:45:28 by fadzejli          #+#    #+#              #
#    Updated: 2026/04/04 12:49:01 by fadwa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract_checker
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp
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