# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 07:19:51 by maouzal           #+#    #+#              #
#    Updated: 2023/04/26 00:38:09 by maouzal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = push_swap.c	parsing.c	utils.c	linked_list.c	operations_push.c	\
	operations_rotat.c	operations_swap.c	operations_rev_rotat.c	small_sort.c	\
	get_min.c	functions.c	ft_split.c	sort_assist.c	push_min_b.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all