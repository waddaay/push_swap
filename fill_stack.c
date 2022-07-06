/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:04:59 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/06 22:05:17 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    fill_stack(int argc, char **argv, t_stack *stack)
{
    int     i;
    int     j;
    int     k;
    char    **ptr;

    i = 0;
    j = 0;
    while (++i < argc)
      {
          ptr = ft_split(argv[i],' ');
          k = 0;
          while (ptr[k])
            stack->body[j++] = ft_atoi(ptr[k++]);
      }
}