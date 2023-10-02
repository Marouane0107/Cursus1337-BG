Name = philo

CC = cc

SRC = philo.c  utils.c  fun_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror  #-fsanitize=thread -g3 -pthread 

all: $(Name)
$(Name): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(Name)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all
