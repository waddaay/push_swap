/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:51:45 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 04:56:00 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	int		div;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1)
	{
		size = stack_size(argc, argv);
		create_stack(size, 0, &stack_a);
		create_stack(size, size, &stack_b);
		div = 3;
		fill_stack(argc, argv, &stack_a);
		if (!check_errors(argc, argv, stack_a))
			ft_putstr_fd("Error\n", 1);
		else if (!is_sorted(stack_a.body, stack_a.size))
		{
			if (size >= 500)
				div = check_div(size, argc, argv);
			push_all_to_b(&stack_a, &stack_b, div, 1);
			push_all_to_a(&stack_a, &stack_b, 1);
		}
		free(stack_a.body);
		free(stack_b.body);
	}
}
