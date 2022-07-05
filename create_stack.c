/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:21:19 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/05 22:53:02 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *create_stack(int    stack_size)
{
    int *our_stack;
    our_stack = malloc(sizeof(int) * stack_size);
    return our_stack;
}

void    fill_stack(int argc, char **argv, int *stack, int stack_size)
{
    int i;
    int j;
    int k;
    char    **ptr;

    i = 0;
    j = 0;
    while (++i < argc)
      {
          ptr = ft_split(argv[i],' ');
          k = 0;
          while (ptr[k])
            stack[j++] = ft_atoi(ptr[k++]);
      }
}