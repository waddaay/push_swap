# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywadday <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 21:39:43 by ywadday           #+#    #+#              #
#    Updated: 2022/07/07 21:05:02 by ywadday          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = so_long.h

SRC = main.c\
	sort.c\
	create_stack.c\
	utils.c\
	push.c\
	swap.c\
	rotate.c\
	fill_stack.c\
	libft/ft_atoi.c\
	libft/ft_strlcpy.c\
	libft/ft_split.c\
	libft/ft_memmove.c\
	libft/ft_putstr_fd.c\
	
OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

	