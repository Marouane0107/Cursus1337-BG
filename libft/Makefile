# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maouzal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 07:22:25 by maouzal           #+#    #+#              #
#    Updated: 2022/10/22 09:07:37 by maouzal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c	ft_memcmp.c	ft_strchr.c	ft_strnstr.c ft_bzero.c ft_memcpy.c ft_strdup.c ft_strrchr.c ft_calloc.c \
	  ft_memmove.c ft_striteri.c ft_strtrim.c ft_isalnum.c ft_memset.c ft_strjoin.c ft_substr.c ft_isalpha.c \
	  ft_putchar_fd.c ft_strlcat.c ft_tolower.c ft_isascii.c ft_putendl_fd.c ft_strlcpy.c ft_toupper.c ft_isdigit.c \
	  ft_putnbr_fd.c ft_strlen.c ft_isprint.c ft_putstr_fd.c ft_strmapi.c ft_itoa.c ft_split.c ft_strncmp.c ft_memchr.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc  $(NAME) $(OBJ)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all

