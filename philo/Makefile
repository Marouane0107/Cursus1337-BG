Name = philo

CC = cc

SRC = philo.c  operations.c  fun_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread #-g3

all: $(Name)
$(Name): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(Name)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all
