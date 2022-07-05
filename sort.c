/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:54:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/05 22:54:35 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *sorted_stack(int *stack_a, int size)
{
    int *stack_s;
    int i;
    int j;
    int tmp;
    
    stack_s = create_stack(size);
    i = 0;
    while (i++ < size)
        push(stack_s, stack_a, size, size);
    i = 0;
    while (i < size)
    {
        j += i;
        while (j < size - i)
        {
            if (stack_s[i] > stack_s[j])
            {
               tmp = stack_s[i];
                stack_s[i] = stack_s[j];
                stack_s[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (stack_s);   
}