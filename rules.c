/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:49:42 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 03:27:21 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rb(t_stack *stack_a, t_stack *stack_b, int *s_tab, t_attr attr)
{
	if (stack_b->body[stack_b->top] <= s_tab[attr.pv2]
		&& stack_a->body[stack_a->top] > s_tab[attr.pv1]
		&& stack_b->top <= stack_b->size - 2
		&& stack_b->body[stack_b->top] >= attr.vp1)
	{
		rr(stack_a, stack_b, "rr\n", attr.b);
		stack_a->count++;
	}
	else if (stack_b->body[stack_b->top] <= s_tab[attr.pv2]
		&& stack_b->top <= stack_b->size - 2
		&& stack_b->body[stack_b->top] >= attr.vp1)
	{
		rotate(stack_b, "rb\n", attr.b);
		stack_a->count++;
	}
}

void	push_ra(t_stack *stack_a, t_stack *stack_b, int *s_tab, t_attr attr)
{
	if (stack_a->body[stack_a->top] <= s_tab[attr.pv1])
	{
		pb(stack_a, stack_b, attr.b);
		stack_a->count++;
		stack_a->pushed++;
	}
	else
	{
		rotate(stack_a, "ra\n", attr.b);
		stack_a->count++;
	}
}

void	rules(t_stack *stack_a, t_stack *stack_b, int *s_tab, t_attr attr)
{
	while (stack_a->pushed <= attr.pv1)
	{
		push_rb(stack_a, stack_b, s_tab, attr);
		push_ra(stack_a, stack_b, s_tab, attr);
	}
}
