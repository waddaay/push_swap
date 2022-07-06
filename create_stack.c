/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:21:19 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/06 22:05:06 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(int    stack_size, int top)
{
    t_stack *our_stack;
    
    our_stack = (t_stack *)malloc(sizeof(t_stack));
    if (!our_stack)
      return (0);
    our_stack->size = stack_size;
    our_stack->top = top;
    our_stack->body = (int *)malloc(sizeof(t_stack) * stack_size);
    if (!our_stack->body)
      return (0);
    return our_stack;
}