/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:21:19 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 03:54:26 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(int stack_size, int top, t_stack *our_stack)
{
	our_stack->size = stack_size;
	our_stack->top = top;
	our_stack->count = 0;
	our_stack->body = (long *)malloc(sizeof(long) * stack_size);
	if (!our_stack->body)
		return ;
}
