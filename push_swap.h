/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:30:33 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/09 02:57:48 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack{
    int size;
    int top;
    int *body;
}t_stack;

int         array_size(char **arr);
int         stack_size(int argc, char **argv);
void        push(t_stack *stack_x, t_stack *stack_y);
t_stack     *sorted_stack(t_stack *stack_a);
t_stack     *create_stack(int    stack_size, int top);
void        fill_stack(int argc, char **argv, t_stack *stack);
void	    ft_putstr_fd(char *s, int fd);
void        pa(t_stack *stack_a, t_stack *stack_b);
void        pb(t_stack *stack_a, t_stack *stack_b);
void        swap(t_stack *stack);
void        sa(t_stack *stack_a);
void        sb(t_stack *stack_b);
void        rotate(t_stack *stack, char *str);
void        rrotate(t_stack *stack, char *str);
void        rr(t_stack *stack_a, t_stack *stack_b);
void        rrr(t_stack *stack_a, t_stack *stack_b);
void        push_all_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, int div);
int         max(t_stack *stack);


#endif