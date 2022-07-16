/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 02:33:37 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 02:34:07 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	is_all_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!is_num(argv[i][j]) && !(argv[i][j] == ' ')
				&& !((argv[i][j] == '-' || argv[i][j] == '+')
				&& is_num(argv[i][j + 1])))
				return (0);
		}
	}
	return (1);
}
