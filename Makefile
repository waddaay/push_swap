# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywadday <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 21:39:43 by ywadday           #+#    #+#              #
#    Updated: 2022/07/15 03:01:13 by ywadday          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
HEADER = push_swap.h

SRC = main.c\
	sort.c\
	create_stack.c\
	utils.c\
	push.c\
	swap.c\
	rotate.c\
	check_div.c\
	instructions.c\
	fill_stack.c\
	libft/ft_atoi.c\
	libft/ft_strlcpy.c\
	libft/ft_split.c\
	libft/ft_memmove.c\
	libft/ft_putstr_fd.c\

SRC_BONUS = 

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		
${NAME_BONUS}: ${OBJ_BONUS}
	@$(CC) $(CFLAGS) $^ -o $@ -I $(HEADER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
