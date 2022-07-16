/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:51:45 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/15 22:25:41 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_memory(t_stack *stack)
{
    if (stack)
        free(stack);
    if (stack->body)
        free(stack->body);
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int size = stack_size(argc, argv);
        int div;
        t_stack *stack_a;
        t_stack *stack_b;

        stack_a = create_stack(size, 0);
        stack_b = create_stack(size, size);
        div = 3;
        fill_stack(argc, argv,stack_a);
        if (!check_errors(argc, argv, *stack_a))
            ft_putstr_fd("Error\n", 1);
        else if(!is_sorted(stack_a->body, stack_a->size))
        {
            if (size >= 500)
                div = check_div(size, argc, argv);
            push_all_to_b(stack_a, stack_b, div, 1);
            push_all_to_a(stack_a, stack_b, 1);
        }
        free_memory(stack_a);
        free_memory(stack_b);
    }
}
