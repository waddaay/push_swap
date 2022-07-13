/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:54:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/13 16:23:35 by ywadday          ###   ########.fr       */
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
// it's better to remove stack s

void push_all_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, int div)
{
    int pv1;
    int pv2;
    int i;
    
    pv1 = stack_s->size / div;
    while (pv1 < stack_a->size - 1)
    {
        stack_s->top = stack_s->top + pv1;
        pv2 = pv1 / 2;
        i = 0;
        while (i++ < stack_s->size - stack_s->top)
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
        pv1 = (stack_s->size + stack_s->top ) / div;
    }
    free(stack_s->body);
    free(stack_b);
}

int max(t_stack *stack)
{
    int max;
    int i;

    i = stack->top;
    max = stack->top;
    while (i < stack->size)
    {
        if (stack->body[i] > stack->body[max])
            max = i;
        i++;
    }
    return (max);
}

void push_all_to_a(t_stack *stack_a, t_stack *stack_b)
{
    int max_indice;
    int max_value;
    int meduim;
    int pushed;
    
    pushed = 0;
    while (stack_a->top > 0)
    {
        meduim = (stack_b->size - stack_b->top) / 2;
        max_indice = max(stack_b);
        max_value = stack_b->body[max_indice];
        if (max_indice == stack_b->top)
            pa(stack_a, stack_b);
        else if (max_indice - stack_b->top < stack_b->size - max_indice)
        {
            while (max_indice >= stack_b->top)
            {
                rotate(stack_b, "rb\n");
                printf("%d %d\n", max_indice, stack_b->size);
                max_indice--;
            }
        }
        else
        {
            while (max_indice < stack_b->size)
            {
                rrotate(stack_b, "rrb\n");
                max_indice++;
                printf("%d %d\n", max_indice, stack_b->size);
            }
        }
        pa(stack_a, stack_b);
        pushed++;
    }
}