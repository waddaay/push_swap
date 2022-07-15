/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:54:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/15 11:38:47 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// it's better to remove stack s and replace it by a simple table (to do later)

t_stack    *sorted_stack(t_stack *stack_a)
{
    t_stack *stack_s;
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
                ft_swap(&stack_s->body[i], &stack_s->body[j]);
            j++;
        }
        i++;
    }
    return stack_s;
}

void *sort_tab(int *tab, int size)
{
    int i;
    int j;
    
    i = -1;
    while (++i < size)
    {
        j = i + i -1;
        while (++j < size)
        {
            if (tab[i] > tab[j])
                ft_swap(&tab[i], &tab[j]);
        }
    }
}

int pick_div(int size, int div)
{
    if (size <= 110)
        div = 3;
    else if (size <= 190)
        div = 4;
    else if (size <= 300)
        div = 5;
    else if (size <= 430)
        div = 6;
    return (div);
}

void push_all_to_b (t_stack *stack_a, t_stack *stack_b, int div, int b)
{
    t_stack *stack_s;
    t_attr  attr;
    
    stack_s = sorted_stack(stack_a);
    attr.vp1 = stack_s->body[0];
    attr.pv1 = (stack_a->size / div);
    attr.pv2 = attr.pv1 / 2;
    stack_a->pushed = 0;
    while (stack_b->top > 1)
    {
        attr.b = b;
        attr.div = div;
        instructions(stack_a, stack_b, stack_s, attr);
        attr.vp1 = stack_s->body[attr.pv1];
        attr.pv2 = attr.pv1;
        div = pick_div(stack_a->size - stack_a->pushed, div);
        attr.pv1 = ((stack_a->size - stack_a->pushed) / div) + stack_a->pushed + 1;
        attr.pv2 = ((attr.pv1 - attr.pv2) / 2) + attr.pv2;
    }  
}

void push_all_to_a(t_stack *stack_a, t_stack *stack_b, int b)
{
    t_attr attr;

    attr.b = b;
    while (stack_a->top > 0)
    {
        push_a(stack_a, stack_b, attr);
    }
}

void push_a(t_stack *stack_a, t_stack *stack_b, t_attr attr)
{
    attr.med = ((stack_b->size - stack_b->top) / 2) + stack_b->top;
    attr.max = max(stack_b);
    attr.max_val = stack_b->body[attr.max];
    if (attr.max <= attr.med)
    {
        while (stack_b->body[stack_b->top] != attr.max_val)
        {
            rotate(stack_b, "rb\n", attr.b);
            stack_a->count++;
        }
    }
    else
    {
        while (stack_b->body[stack_b->top] != attr.max_val)
        {
            rrotate(stack_b, "rrb\n", attr.b);
            stack_a->count++;
        }
    }
    pa(stack_a, stack_b, attr.b);
    stack_a->count++;
}
