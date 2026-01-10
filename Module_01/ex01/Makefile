NAME = hordes
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
	Zombie.cpp \
	zombieHorde.cpp
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