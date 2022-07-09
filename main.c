/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:51:45 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/09 03:03:18 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int size = stack_size(argc, argv);
    t_stack *stack_a, *stack_b, *stack_s;

    stack_a = create_stack(size, 0);
    stack_b = create_stack(size, size);
    fill_stack(argc, argv,stack_a);
    stack_s = sorted_stack(stack_a);
    // printf("%d", stack_a->body[0]);
    // for (int i = 0; i < stack_a->size; i++)
    //     printf("%d\n", stack_a->body[i]);
    // for (int i = stack_s->top; i < stack_s->size; i++)
    //     printf("%d, ", stack_s->body[i]);
    push_all_to_b(stack_a, stack_b, stack_s, 3);
    // for (int i = 0; i < stack_a->size; i++)
    //     pb(stack_a, stack_b);
    // for (int i = 0; i < stack_b->size; i++)
    //     printf("%d\n", stack_b->body[i]);

    // printf("\n---------------------------\n");
    // for (int i = 0; i < stack_b->size; i++)
    //     pa(stack_a, stack_b);
    for (int i = stack_a->top; i < stack_a->size; i++)
        printf("%d, ", stack_a->body[i]);

    printf("\n---------------------------\n");
    
    // for (int i = 0; i < stack_a->size; i++)
    //     rrotate(stack_a, "rra\n");
    // for (int i = 0; i < stack_a->size; i++)
    //     printf("%d\n", stack_a->body[i]);
    for (int i = stack_b->top; i < stack_b->size; i++)
        printf("%d, ", stack_b->body[i]);
    printf("\n\n%d", max(stack_b));
    printf("\n\n%d", max(stack_a));
    printf("\n\n%d", max(stack_s));
    
    
}
