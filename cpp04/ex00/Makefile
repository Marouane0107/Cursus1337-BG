NAME = Animal

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = WrongCat.cpp WrongAnimal.cpp Dog.cpp Cat.cpp Animal.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)

re: fclean all

.PHONNY: all clean fclean re
