/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:56:30 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 04:52:08 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	stack_size(int argc, char **argv)
{
	int		i;
	int		k;
	int		stack_size;
	char	**ptr;

	i = 0;
	stack_size = 0;
	while (++i < argc)
	{
		ptr = ft_split(argv[i], ' ');
		stack_size += array_size(ptr);
		k = -1;
		while (ptr[++k])
			free(ptr[k]);
		free(ptr);
	}
	return (stack_size);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	max(t_stack *stack)
{
	int	max;
	int	i;

	i = stack->top;
	max = stack->top;
	while (i < stack->size)
	{
		if (stack->body[i] > stack->body[max])
			max = i;
		i++;
	}
	return (max);
}
