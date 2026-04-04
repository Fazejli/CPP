# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 14:47:58 by fadzejli          #+#    #+#              #
#    Updated: 2026/04/03 12:13:04 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamontrap
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) -I. $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -I. -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re