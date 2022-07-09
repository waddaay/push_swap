/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:54:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/09 03:04:03 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack    *sorted_stack(t_stack *stack_a)
{
    t_stack *stack_s;
    int     tmp;
    int     i;
    int     j;
    
    stack_s = create_stack(stack_a->size, 0);
    i = -1;
    while (i++ < stack_a->size)
    {
        stack_s->body[i] = stack_a->body[i];
    }
    i = 0;
    while (i < stack_s->size)
    {
        j = i + 1;
        while (j < stack_s->size)
        {
            if (stack_s->body[i] > stack_s->body[j])
            {
                tmp = stack_s->body[i];
                stack_s->body[i] = stack_s->body[j];
                stack_s->body[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return stack_s;
}

void push_all_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, int div)
{
    int pv1;
    int pv2;
    int i;
    
    pv1 = stack_s->size / div;
    while (pv1 < stack_a->size - 1)
    {
        pv1 = (stack_s->size + stack_s->top) / div;
        if (pv1 >= stack_a->size)
            pv1 = stack_a->size - 1;
        stack_s->top = stack_s->top + pv1;
        pv2 = pv1 / 2;
        i = 0;
        while (i++ < stack_s->size)
        {
            
            if (stack_a->body[stack_a->top] < stack_s->body[pv1])
            {
                pb(stack_a, stack_b);
                if (stack_b->top + 2 < stack_b->size)
                {
                    if (stack_b->body[stack_b->top] > stack_s->body[pv2])
                        rotate(stack_b, "rb\n");
                }
            }        
            else
                rotate(stack_a, "ra\n");
        }
    }
    free(stack_s->body);
    free(stack_b);
}

int max(t_stack *stack)
{
    int max;
    int i;

    i = stack->top;
    // printf("top : %d, size : %d", stack->top, stack->size);
    max = stack->body[stack->top];
    while (i < stack->size)
    {
        if (stack->body[i] > max)
            max = stack->body[i];
        i++;
    }
    return (max);
}