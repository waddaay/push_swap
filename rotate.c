/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:57:36 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/08 00:05:43 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack, char *str)
{
    int tmp1;
    int tmp2;
    int i;

    if (stack->top < stack->size - 1)
        return ;
    tmp1 = stack->body[stack->size - 1];
    stack->body[stack->size - 1] = stack->body[stack->top];
    i = stack->size - 2;
    while (i >= 0)
    {
        tmp2 = stack->body[i];
        stack->body[i] = tmp1;
        tmp1 = tmp2;
        i--;
    }
    ft_putstr_fd(str, 1);
}

void rrotate(t_stack *stack, char *str)
{
    int tmp1;
    int tmp2;
    int i;

    if(stack->top < stack->size - 1)
        return ;
    tmp1 = stack->body[stack->top];
    stack->body[stack->top] = stack->body[stack->size - 1];
    i = 1;
    while (i < stack->size)
    {
        tmp2 = stack->body[i];
        stack->body[i] = tmp1;
        tmp1 = tmp2;
        i++;
    }
    ft_putstr_fd(str, 1);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a, "ra\n");
    rotate(stack_b, "rb\n");
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rrotate(stack_a, "rra\n");
    rrotate(stack_b, "rrb\n");
}

