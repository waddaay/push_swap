/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:41:59 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/15 18:44:16 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(t_attr attr)
{
    attr.i = 1;
    attr.count = attr.tab[0];
    while (attr.i < 5)
    {
    if (attr.count > attr.tab[attr.i])
    {
        attr.count = attr.tab[attr.i];
        attr.div = attr.i + 4;
    }
     attr.i++;
    }
    return (attr.div);
}

int check_div(int size, int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_attr attr;

    attr.i = 0;
    attr.div = 4;
    while (attr.i < 5)
    {
        stack_a = create_stack(size, 0);
        stack_b = create_stack(size, size);
        fill_stack(argc, argv ,stack_a);
        push_all_to_b(stack_a, stack_b, 4 + attr.i, 0);
        push_all_to_a(stack_a, stack_b, 0);
        attr.tab[attr.i++] = stack_a->count;
        free_memory(stack_a);
        free_memory(stack_b);
    }
    return(get_min(attr));
} 


