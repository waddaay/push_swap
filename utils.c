/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:56:30 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/05 22:56:41 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int array_size(char **arr)
{
    int i = 0;
    int size = 0;
    while (arr[i])
        i++;
    return (i);
}

int stack_size(int argc, char **argv)
{
    int i;
    int j;
    int stack_size;
    char    **ptr;

    i = 0;
    stack_size = 0;
    while (++i < argc)
      {
          ptr = ft_split(argv[i],' ');
          stack_size += array_size(ptr);
      }
      return (stack_size);
}
