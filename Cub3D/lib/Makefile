# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 16:00:51 by rerayyad          #+#    #+#              #
#    Updated: 2024/01/05 05:42:52 by maouzal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = lib.a
FILES = ft_isdigit.c ft_isalnum.c ft_atoi.c ft_strrchr.c ft_striteri.c \
				ft_split.c ft_calloc.c ft_strjoin.c ft_strmapi.c ft_isalpha.c \
				ft_bzero.c ft_strlcat.c ft_isascii.c ft_isprint.c ft_strlcpy.c \
				ft_strncmp.c ft_strdup.c ft_itoa.c ft_memchr.c ft_memcmp.c \
				ft_memmove.c ft_memcpy.c  ft_strchr.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_strnstr.c \
				ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_isxdigit.c\
				get_next_line.c 
OBJS = $(FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I ../mandatory/includes/
AR = ar rc

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $<
	@$(AR) $(NAME) $@

$(NAME): $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re 
