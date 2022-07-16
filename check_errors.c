/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:18:29 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/15 18:26:04 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int is_num(char c)
{
    if (!(c >= '0' && c <= '9'))
        return (0);
    return (1);
}
int is_all_numeric(int argc, char **argv)
{
    int i;
    int j;
    
    i = 0;
    while (++i < argc)
    {
        j = -1;
        while (argv[i][++j])
        {
            if (!is_num(argv[i][j]) && !(argv[i][j] == ' ')
                && !((argv[i][j] == '-' || argv[i][j] == '+') && is_num(argv[i][j + 1])))
                return (0);
        }
    }
    return (1);
}

int check_double(long *tab, int size)
{
    int i;
    int j;
    i = -1;
    while (++i < size - 1)
    {
        j = i+1;
        while(j < size)
        {
            if (tab[i] == tab[j++])
                return (0);
        }
    }
    return (1);
}

int check_maxint(long *tab, int size)
{
    long    num;
    int     i;
    
    i = -1;
    while (++i < size) 
    {
        num = tab[i];
        if (num > 2147483647 || num < -2147483648)
            return (0);
    }
    return (1);
}

int is_sorted(long *tab, int size)
{
    int i;
    
    i = -1;
    while(++i < size - 1)
    {
        if(tab[i] > tab[i + 1])
            return (0);
    }
    return (1);
}

int check_errors(int argc, char **argv, t_stack stack)
{
    if (!is_all_numeric(argc, argv) || !check_double(stack.body, stack.size)
        || !check_maxint(stack.body, stack.size))
        return (0);
    return (1);
}
