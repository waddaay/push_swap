/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:40:39 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/08 21:02:29 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack *stack_x, t_stack *stack_y)
{
    stack_y->body[--stack_y->top] = stack_x->body[stack_x->top++];
}

// push top element from stack A to stack B
void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->top == stack_b->size)
        return ;
    push(stack_b, stack_a);
    ft_putstr_fd("pa\n", 1);
}

// push top element from stack B to stack A
void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top == stack_a->size)
        return ;
    push(stack_a, stack_b);
    ft_putstr_fd("pb\n", 1);
}

