Name = philo

CC = cc

SRC = philo.c  utils.c  fun_utils.c

OBJ = $(SRC:.c=.o)

CFLAGC = -Wall -Wextra -Werror

all: $(Name)
$(Name): $(OBJ)
	$(CC) $(CFLAGC) $(OBJ) -o $(Name)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all

