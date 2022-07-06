/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:30:33 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/06 17:01:07 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int     array_size(char **arr);
int     stack_size(int argc, char **argv);
void    swap(int    *stack, int size);
void    rotate(int *stack, int size);
void    rrotate(int *stack, int size);
void    push(int *stack_x, int *stack_y, int size_x, int size_y);
int     *sorted_stack(int *stack_a, int size);
int     *create_stack(int    stack_size);
void    fill_stack(int argc, char **argv, int *stack, int stack_size);


#endif