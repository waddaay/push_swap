/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:57:36 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 03:26:33 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char *str, int b)
{
	int	tmp1;
	int	tmp2;
	int	i;

	if (stack->top > stack->size - 1)
		return ;
	tmp1 = stack->body[stack->size - 1];
	stack->body[stack->size - 1] = stack->body[stack->top];
	i = stack->size - 2;
	while (i >= 0)
	{
		tmp2 = stack->body[i];
		stack->body[i] = tmp1;
		tmp1 = tmp2;
		i--;
	}
	if (str && b == 1)
		ft_putstr_fd(str, 1);
}

void	rrotate(t_stack *stack, char *str, int b)
{
	int	tmp1;
	int	tmp2;
	int	i;

	if (stack->top > stack->size - 1)
		return ;
	tmp1 = stack->body[stack->top];
	stack->body[stack->top] = stack->body[stack->size - 1];
	i = stack->top + 1;
	while (i < stack->size)
	{
		tmp2 = stack->body[i];
		stack->body[i] = tmp1;
		tmp1 = tmp2;
		i++;
	}
	if (str && b == 1)
		ft_putstr_fd(str, 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, char *str, int b)
{
	rotate(stack_a, NULL, 0);
	rotate(stack_b, NULL, 0);
	if (b == 1)
		ft_putstr_fd(str, 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrotate(stack_a, "rra\n", 0);
	rrotate(stack_b, "rrb\n", 0);
}
