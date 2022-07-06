# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywadday <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 21:39:43 by ywadday           #+#    #+#              #
#    Updated: 2022/07/06 16:52:21 by ywadday          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c/
	create_stack.c/
	sort.c/
	utils.c/
	rules.c/

all : $(NAME)

$(NAME) :
	gcc -c $(SRC)
	gcc -Wall -Wextra -Werror  *.o  -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	
re : fclean all