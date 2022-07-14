/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:54:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/14 05:03:46 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// it's better to remove stack s

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

void push_all_to_b (t_stack *stack_a, t_stack *stack_b, int div)
{
    t_stack *stack_s;
    int     pv1;
    int     pv2 = 0;
    int     i;
    int     pushed;
    stack_s = sorted_stack(stack_a);
    int vp1 = stack_s->body[0];
    pv1 = stack_a->size / div;
    pushed = 0;
    while (stack_b->top > 1)
    {
        pv2 = (pv1 / 2) + pv2;
        i = 0;
        while (pushed <= pv1)
        {
            if (stack_b->body[stack_b->top] <= stack_s->body[pv2] && stack_a->body[stack_a->top] > stack_s->body[pv1] && stack_b->top <= stack_b->size - 2 && stack_b->body[stack_b->top] >= vp1)
                rr(stack_a, stack_b);
            else if (stack_b->body[stack_b->top] <= stack_s->body[pv2] && stack_b->top <= stack_b->size - 2 && stack_b->body[stack_b->top] >= vp1)
                    rotate(stack_b, "rb\n");
            if (stack_a->body[stack_a->top] <= stack_s->body[pv1])
            {
                pb(stack_a, stack_b);
                pushed++;
            }
            else
                rotate(stack_a, "ra\n");
        }
        vp1 = stack_s->body[pv1];
        pv1 = ((stack_a->size - pushed) / div) + pushed;
    }  
}

void push_all_to_a(t_stack *stack_a, t_stack *stack_b)
{
    int max_indice;
    int max_value;
    int meduim = 0;
    
    while (stack_a->top > 0)
    {
        meduim = ((stack_b->size - stack_b->top) / 2) + stack_b->top;
        max_indice = max(stack_b);
        max_value = stack_b->body[max_indice];
        if (max_indice <= meduim)
        {
            while (stack_b->body[stack_b->top] != max_value)
                rotate(stack_b, "rb\n");
        }
        else
        {
            while (stack_b->body[stack_b->top] != max_value)
                rrotate(stack_b, "rrb\n");
        }
        pa(stack_a, stack_b);
    }
}