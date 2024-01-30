# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 07:19:51 by maouzal           #+#    #+#              #
#    Updated: 2024/01/30 06:12:39 by maouzal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = push_swap.c	parsing.c	utils.c	linked_list.c	operations_push.c	\
	operations_rotat.c	operations_swap.c	operations_rev_rotat.c	small_sort.c	\
	get_max.c	functions.c	ft_split.c	sort_assist.c	push_max_a.c	big_sort.c	\

SRC2 = checker_bonus/main_bonus.c	checker_bonus/check_input_bonus.c	checker_bonus/utils_bonus.c \
	checker_bonus/operations_bonus.c	checker_bonus/function_bonus.c	checker_bonus/get_next_line_bonus.c \
	checker_bonus/get_next_line_utils_bonus.c	checker_bonus/push_bonus.c	checker_bonus/ft_split_bonus.c \
	checker_bonus/rotat_bonus.c	checker_bonus/rrotat_bonus.c	checker_bonus/swap_bonus.c \
	checker_bonus/linked_list_bonus.c \

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	 
bonus : $(NAME2)

$(NAME2): $(OBJ2)
	@$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)
clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ2)
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)

re: fclean all