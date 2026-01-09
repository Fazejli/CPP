NAME = MonRepertoire
CC = c++
FLAGS = -Wall -Wextra -Werror -str=c++98
SRCS = Contact.cpp \
		PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)
INC = Contact.hpp \
	PhoneBook.hpp

all : $(NAME

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