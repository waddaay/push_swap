/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:04:52 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 04:55:48 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	check_instructions(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a, NULL, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b, NULL, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b, NULL, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rrotate(stack_a, NULL, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrotate(stack_b, NULL, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else
		ft_putstr_fd("error\n", 2);
}

void	read_rules(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		check_instructions(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		size;

	size = stack_size(argc, argv);
	create_stack(size, 0, &stack_a);
	create_stack(size, size, &stack_b);
	fill_stack(argc, argv, &stack_a);
	if (!check_errors(argc, argv, stack_a))
		ft_putstr_fd("Error\n", 1);
	else
	{
		read_rules(&stack_a, &stack_b);
		if (stack_b.top == stack_b.size
			&& is_sorted(stack_a.body, stack_b.size))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	free(stack_a.body);
	free(stack_b.body);
}
