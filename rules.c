/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:55:20 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/05 22:55:34 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(int    *stack, int size)
{
    int tmp;
    if(size >= 2)
    {
        tmp = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp;
    }
}


void    rotate(int *stack, int size)
{
    int i;
    int tmp1;
    int tmp2;

    i = 1;
    tmp1 = stack[--size];
    stack[size] = stack[0];
    while(size--)
    {
        tmp2 = stack[size];
        stack[size] = tmp1;
        tmp1 = tmp2;
    }
}


void    rrotate(int *stack, int size)
{
    int i;
    int tmp1;
    int tmp2;

    i = 1;
    tmp1 = stack[0];
    stack[0] = stack[size-1];
    while(i < size)
    {
        tmp2 = stack[i];
        stack[i++] = tmp1;
        tmp1 = tmp2;
    }

}

void    push(int *stack_x, int *stack_y, int size_x, int size_y)
{
    int tmp1;
    int tmp2;
    int i;

    if (size_y == 0) return ;
    tmp1 = stack_x[0];
    stack_x[0] = stack_y[0];
    i = 1;
    while(i < size_x)
    {
        tmp2 = stack_x[i];
        stack_x[i++] = tmp1;
        tmp1 = tmp2;
    }
    if (size_y == 1) return ;
    rotate(stack_y, size_y);
    stack_y[--size_y] = 0;
}
