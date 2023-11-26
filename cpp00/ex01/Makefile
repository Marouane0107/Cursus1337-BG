NAME = PhoneBook

CXX = c++

CXXFLAG = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp contacts.cpp 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) 
		 $(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re