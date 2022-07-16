/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:54:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 04:07:13 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(long *tab, int size)
{
	int	i;
	int	j;
	int	*ptr;

	ptr = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	i = -1;
	while (++i < size)
	{
		ptr[i] = tab[i];
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (ptr[i] < ptr[j])
				ft_swap(&ptr[i], &ptr[j]);
		}
	}
	return (ptr);
}

int	pick_div(int size, int div)
{
	if (size <= 110)
		div = 3;
	else if (size <= 190)
		div = 4;
	else if (size <= 300)
		div = 5;
	else if (size <= 430)
		div = 6;
	return (div);
}

void	push_all_to_b(t_stack *stack_a, t_stack *stack_b, int div, int b)
{
	int		*s_tab;
	t_attr	attr;

	attr.i = -1;
	s_tab = sort_tab(stack_a->body, stack_a->size);
	attr.vp1 = s_tab[0];
	attr.pv1 = (stack_a->size / div);
	attr.pv2 = attr.pv1 / 2;
	stack_a->pushed = 0;
	while (stack_b->top > 1)
	{
		attr.b = b;
		attr.div = div;
		rules(stack_a, stack_b, s_tab, attr);
		attr.vp1 = s_tab[attr.pv1];
		attr.pv2 = attr.pv1;
		div = pick_div(stack_a->size - stack_a->pushed, div);
		attr.pv1 = ((stack_a->size - stack_a->pushed) / div)
			+ stack_a->pushed + 1;
		attr.pv2 = ((attr.pv1 - attr.pv2) / 2) + attr.pv2;
	}
	free(s_tab);
}

void	push_all_to_a(t_stack *stack_a, t_stack *stack_b, int b)
{
	t_attr	attr;

	attr.b = b;
	while (stack_a->top > 0)
	{
		push_a(stack_a, stack_b, attr);
	}
}

void	push_a(t_stack *stack_a, t_stack *stack_b, t_attr attr)
{
	attr.med = ((stack_b->size - stack_b->top) / 2) + stack_b->top;
	attr.max = max(stack_b);
	attr.max_val = stack_b->body[attr.max];
	if (attr.max <= attr.med)
	{
		while (stack_b->body[stack_b->top] != attr.max_val)
		{
			rotate(stack_b, "rb\n", attr.b);
			stack_a->count++;
		}
	}
	else
	{
		while (stack_b->body[stack_b->top] != attr.max_val)
		{
			rrotate(stack_b, "rrb\n", attr.b);
			stack_a->count++;
		}
	}
	pa(stack_a, stack_b, attr.b);
	stack_a->count++;
}
