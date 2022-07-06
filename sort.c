/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:54:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/06 19:22:20 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack    *sorted_stack(t_stack *stack_a)
{
    t_stack *stack_s;
    int     tmp;
    int     i;
    int     j;
    
    stack_s = create_stack(stack_a->size);
    ft_memmove(stack_s, stack_a, stack_a->size*4);
    i = 0;
    while (i < stack_s->size)
    {
        j = i + 1;
        while (j < stack_s->size)
        {
            if (stack_s->body[i] < stack_s->body[j])
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