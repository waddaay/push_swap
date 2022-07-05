/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:51:45 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/05 05:05:28 by ywadday          ###   ########.fr       */
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
    int tmp1, tmp2;
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


int main(int argc, char **argv)
{
    int size = stack_size(argc, argv);
    int *stack_a, *stack_b;
    int i = 0;

    stack_a = create_stack(size);
    stack_b = create_stack(size);

    stack_b[0] = -9;
    stack_b[1] = 1;
    stack_b[2] = 2;
    stack_b[3] = 7;
    
    fill_stack(argc, argv, stack_a, size);
    push(stack_a,stack_b, size, size);
    while (i < size)
        printf("%d\n", stack_b[i++]);
    
}

