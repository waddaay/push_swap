/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:41:59 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/14 23:19:13 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_div(int size, int argc, char **argv)
{
    t_stack *stack_a, *stack_b;
    int count;
    int div;
    int tab[5];
    int i;

    i = 0;
    div = 4;
    while (i < 5)
    {
        stack_a = create_stack(size, 0);
        stack_b = create_stack(size, size);
        fill_stack(argc, argv ,stack_a);
        push_all_to_b(stack_a, stack_b, 4 + i, 0);
        push_all_to_a(stack_a, stack_b, 0);
        tab[i++] = stack_a->count;
    }
    i = 1;
    count = tab[0];
    while (i < 5)
    {
        if (count > tab[i])
        {
            count = tab[i];
            div = i + 4;
        }
        i++;
    }
    return (div);
} 

