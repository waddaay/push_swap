/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:09:22 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/15 23:20:58 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack)
{
    int tmp;

    tmp = stack->body[stack->top];
    stack->body[stack->top] = stack->body[stack->top + 1];
    stack->body[stack->top + 1] = tmp;
}

void sa(t_stack *stack_a, int b)
{
    if (stack_a->top == stack_a->size)
        return ;
    swap(stack_a);
    if (b == 1)
        ft_putstr_fd("sa\n", 1);
}

void sb(t_stack *stack_b,int b)
{
    if (stack_b->top == stack_b->size)
        return ;
    swap(stack_b);
    if(b == 1)
        ft_putstr_fd("sb\n", 1);
}

void ss(t_stack *stack_a, t_stack *stack_b, int b)
{
    if (stack_a->top == stack_a->size && stack_b->top == stack_b->size)
        return ;
    sa(stack_a, 0);
    sb(stack_b, 0);
    if (b == 1)
        ft_putstr_fd("ss\n", 1);
}