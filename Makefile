# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywadday <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 21:39:43 by ywadday           #+#    #+#              #
#    Updated: 2022/07/15 22:56:05 by ywadday          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
HEADER = push_swap.h

SRC = sort.c\
	create_stack.c\
	utils.c\
	push.c\
	swap.c\
	rotate.c\
	check_div.c\
	instructions.c\
	fill_stack.c\
	ft_atoi.c\
	ft_strlcpy.c\
	ft_split.c\
	ft_putstr_fd.c\
	check_errors.c\


SRC_BONUS =	checker.c\
 			gnl.c\
			gnl_utils.c\

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) 
		$(CC) $(CFLAGS) push_swap.c $(OBJ) -o $(NAME)

bonus:${NAME_BONUS}

${NAME_BONUS}: ${OBJ_BONUS} $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ -I $(HEADER)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJ) ${OBJ_BONUS}

fclean : clean
	rm -rf $(NAME)	$(NAME_BONUS)

re : fclean all
