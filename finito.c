/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finito.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:17:29 by kslik             #+#    #+#             */
/*   Updated: 2022/12/17 19:35:18 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int min_nbr(int *stack, int l)
{
    int i = 0;
    int f = 0;
    int m = stack[0];
    while(i < l)
    {
        if(stack[i] < m)
        {
            m = stack[i];
            f = i;
        }
        i++;
    }
    return(f);
}
int *sort_check(int *stack, int l)
{
    int *stackb = stack;
    int i = 0;
    int tmp[1];
    int m = l;
    while(m >= 0)
    {
        i = l - 1;
        while(i > 0)
        {
            if(stackb[i - 1] < stackb[i])
            {
                tmp[0] = stackb[i];
                stackb[i] = stackb[i - 1];
                stackb[i - 1] = tmp[0];
            }
            i--;
        }
        m--;
    }
    i = l - 1 ;
    while (i >= 0)
    {
        ft_printf("%d ", stack[i]);
        i--;
    }
    return(stack);
}
void sort(int *stack, int *stackb, int l)
{
    int min;
    int topa;
    int m = 0;
    int pbn = 0;
    int place = 0;
    int pan = 0;
    while(m < 30)
    {
        place = min_nbr(stack, l);
        topa = l - pbn - 1;
        // ft_printf("top=(%d) {%d}", topa, place);
        if(place == 0)
            ra(stack, l, pbn);
        else if(place == topa)
        {
            pb(stack, stackb, l, &pbn);
        }
        else if (place == topa - 1)
            sa(stack, l);
        m++;
    }
    if(pbn > 0)
    {
        while(pbn != pan)
        {
            pa(stack, stackb, pbn, l, &pan);
        }
    }
    printa(stack, l, pbn, pan);
}