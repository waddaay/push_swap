/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:51:45 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/05 22:57:00 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
    int size = stack_size(argc, argv);
    int *stack_a, *stack_b, *stack_s;
    int i = 0;

    stack_a = create_stack(size);
    stack_b = create_stack(size);

    stack_b[0] = -9;
    stack_b[1] = 1;
    stack_b[2] = 2;
    stack_b[3] = 7;
    
    fill_stack(argc, argv, stack_a, size);
    push(stack_a,stack_b, size, size);
    stack_s = sorted_stack(stack_a, size);
    while (i < size)
        printf("%d\n", stack_s[i++]);
}