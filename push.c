/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:09:56 by kslik             #+#    #+#             */
/*   Updated: 2022/12/22 16:06:05 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void printa(int *stack, int l, int pbn, int pan)
{
    int m = l - pbn - 1 + pan;
    while(m >= 0)
    {
        ft_printf("%d\n",stack[m]);
        m--;
    }
    ft_printf("\na\n");
}
void printb(int *stack,int pbn, int pan)
{
  
    int m = pbn - pan - 1;
    while(m >= 0)
    {
        ft_printf("%d\n",stack[m]);
        m--;
    }
    ft_printf("\nb\n");
}

void rb(int *stackb, int pbn)
{
    ft_printf("rb\n");

    int i;
    i = 0;
    stackb[pbn] = stackb[0];
    while(i < pbn)
    {
        stackb[i] = stackb[i + 1];
        i++;
    }
    stackb[pbn] = '\0';
}
void pb(int *stack,int *stackb, int l, int *pbn)
{
    ft_printf("pb\n");
    static int m = 0;
    static int topb = 0;
    stackb[topb] = stack[m];
    stack[m] = '\0';
    topb++;
    m++;
    (*pbn)++;
}
void ra(int *stack, int l,int pbn)
{
    ft_printf("ra\n");

    int i;
    i = pbn;
    int m;
    m = l;
    stack[m] = stack[pbn];
    while(i < m)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[m] = '\0';
}
void rrb(int *stackb, int pbn)
{
    ft_printf("rrb\n");

    int m ;
    int i = pbn;
    int tmp[0];
    tmp[0] = stackb[i - 1];
    m = i - 1;
    while(m > 0)
    {
        stackb[m] = stackb[m - 1];
        m--;
    }
    stackb[0] = tmp[0];
    stackb[i] = '\0';
}
void rra(int *stack, int l, int pbn)
{
    ft_printf("rra\n");

    int m ;
    int i = l - 1;
    int tmp[0];
    tmp[0] = stack[i];
    m = i ;
    while(m > pbn)
    {
        stack[m] = stack[m - 1];
        m--;
    }
    stack[pbn] = tmp[0];
    stack[i + 1] = '\0';
}
void rrr(int *stack, int *stackb, int l, int pbn)
{
    rra(stack, l, pbn);
    rrb(stackb, pbn);

}
void rr(int *stack, int l, int pbn, int *stackb)
{
    ra(stack, l, pbn);
    rb(stackb, pbn);
}
void pa(int *stack,int *stackb, int pbn, int l, int *pan)
{
    ft_printf("pa\n");
    static int m = 1;
    int topb = pbn - m;
    static int b = 1;
    stack[b] = stackb[topb];
    stackb[topb] = '\0';
    m++;
    b--;
    (*pan)++;
}
int sb1(int *stackb, int l)
{
    ft_printf("sb\n");

    int i = 0;
    int m = 0;
    int tmp[1];
    if(l > 1)
    {
        tmp[0] = stackb[0];
        stackb[0] = stackb[1];
        stackb[1] = tmp[0];
        m++;
    }
    return(m);
}
int sb(int *stackb, int l)
{
    ft_printf("sb\n");
    int i = 0;
    int m = 0;
    int tmp[1];
    if(l > 1)
    {
        tmp[0] = stackb[0];
        stackb[0] = stackb[1];
        stackb[1] = tmp[0];
        m++;
    }
    return(m);
}
void sa(int *stack, int l, int pbn)
{
   
    ft_printf("sa\n");
    int i = 0;
    int tmp[1];
    if(l >= 1)
    {
        tmp[0] = stack[pbn];
        stack[pbn] = stack[pbn + 1];
        stack[pbn + 1] = tmp[0];
    }
}
int mn(int *stack, int l, int m)
{
    int i = m;
    int in = 1000;
    int re = 0;
    while(i < l)
    {
        if(stack[i] < in)
        {
            in = stack[i];
            re = i;
        }
        i++;
    }
    return(re);
}
void sa1(int *stack, int l, int m)
{
    ft_printf("sa\n");
    int i = 0;
    int tmp[1];
    if(l > 1 && l < m)
    {
        tmp[0] = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp[0];
    }
    else
        {
            int i = 0;
            int tmp[1];
            if(l >= 1)
            {
                tmp[0] = stack[0];
                stack[0] = stack[1];
                stack[1] = tmp[0];
            }
        }
}
void ss(int *stack, int *stackb, int l)
{
    ft_printf("Exec ss\n");
    int m;
    m = sb1(stackb, l);
    sa1(stack,l, m);
    
}
void case_of_3(int *stack, int l)
{
    if(stack[0] < stack[1] && stack[1] < stack[2] && stack[2] > stack[0])
        return;
    else if(stack[0] > stack[1] && stack[2] > stack[0])
        sa(stack, l,0);
    else if(stack[0] > stack[1] && stack[1] > stack[2])
    {    
        sa(stack, l,0);
        rra(stack,l, 0);
    }
    else if(stack[0] > stack[1] && stack[1] < stack[2])
        ra(stack, l, 0);
    else if(stack[0] < stack[1] && stack[2] > stack[0])
    {
        sa(stack, l,0);
        ra(stack, l, 0);
    }
    else if(stack[0] < stack[1] && stack[1] > stack[2]) 
        rra(stack, l, 0);
}
void min_to_top(int *stack, int l, int pbn, int m)
{
    int min = mn(stack, l, m);
    if(min == m + 0)
        return;
    if(min == m + 1)
       ra(stack,l, pbn);
    if(min == m + 2)
    {
        ra(stack, l, pbn);
        ra(stack, l, pbn);
    }
    if(min == m + 3)
        rra(stack, l, pbn);
}
void case_of_4(int *stack, int *stackb, int l, int m)
{
    int pan = m;
    int pbn = m;
    min_to_top(stack, l, pbn, m);

    pb(stack, stackb, l, &pbn);
    // ft_printf("%d %d %d %d %d\n", stack[0], stack[1], stack[2], stack[3], stack[4]);

    if(stack[m + 1] < stack[m + 2] && stack[m + 2] < stack[m+3] && stack[m + 3] > stack[m + 1])
                    ;
    else if(stack[m + 1] > stack[m + 2] && stack[m + 3] > stack[m + 1])
        sa(stack, l, pbn);
    else if(stack[m + 1] > stack[m + 2] && stack[m + 2] > stack[m + 3])
    {    
        sa(stack, l, pbn);
        rra(stack,l, m);
    }
    else if(stack[m + 1] > stack[m + 2] && stack[m + 2] < stack[m + 1])
        ra(stack, l, m);
    else if(stack[m + 1] < stack[m + 2] && stack[m + 3] > stack[m + 1])
    {
        sa(stack, l,m);
        ra(stack, l, m);
    }
    else if(stack[m + 1] < stack[m + 2] && stack[m + 2] > stack[m +3]) 
        rra(stack, l, m);
    // ft_printf("{%d %d}", stackb[0], stackb[1]);

    pa(stack, stackb, pbn,l, &pan);
}
void min_to_top5(int *stack, int l, int pbn)
{
    int min= mn(stack, l, 0);
    if(min == 0)
        return;
    if(min == 1)
        ra(stack, l, 0);
    if(min == 2)
    {
        ra(stack, l, 0);
        ra(stack, l, 0);
    }
    if(min == 3)
    {
        rra(stack, l, pbn);
        rra(stack, l, pbn);
    }
    if(min == 4)
        rra(stack, l, pbn);
}
void case_of_5(int *stack, int *stackb, int l)
{
    int pan = 0;
    int pbn = 0;
    min_to_top5(stack, l, pbn);
    // ft_printf("%d %d %d %d %d \n", stack[0], stack[1], stack[2], stack[3], stack[4]);

    pb(stack, stackb, l, &pbn);
    pbn++;
    if(quit(stack, pbn, l) != 1)
        case_of_4(stack, stackb,l, 1);
    pan++;
    pa(stack, stack, pbn, l, &pan);
    // ft_printf("%d %d %d %d %d \n", stack[0], stack[1], stack[2], stack[3], stack[4]);

}
void case_of_2(int *stack, int l)
{
    if(stack[0] > stack[1])
        sa(stack, l, 0);
}
int quit(int *stack, int pbn, int l)
{
    int i = pbn;
    while(i < l)
    {
        if(stack[i] < stack[i - 1])
            return(0);
        i++;  
    }
    return(1);
}
void finish(int *stack, int *stackb , int l)
{
    int pbn = 0;
    int pan = 0;
    int min;
    int total;
    while(quit(stack, pbn, l) != 1) 
    {
        // ft_printf("{%d}", pbn);
        total = l - pbn;
        // ft_printf("total = %d", total / 2);

        min = mn(stack, l, pbn);
        // ft_printf("min = %d", min);

        if(min == pbn)
            pb(stack, stackb, l, &pbn);
        else if(min >= total / 2 )
            rra(stack, l, pbn);
        else if(min < total / 2)
            ra(stack,l, pbn);
    }
    total = pbn;
    while(total > 0)
    {
        pa(stack, stackb, pbn, l, &pan);
        total--;
    }
}
void va(int l, int *arr)
{
    int stack[l];
    int stackb[l];
    int count = 0;
    while(count < l)
    {
        stack[count] = arr[count];
        count++;
    }
    //----------------//
    // ra(stack, l, pbn);
    // sa(stack, l);
    // pb(stack, stackb, l, &pbn);
    // pb(stack, stackb, l, &pbn);
    // pb(stack, stackb, l, &pbn);
    // pushswap(stack, stackb, l, pbn);
    // rrr(stack, stackb, l, pbn);
    // if(l == 2)
    //     case_of_2(stack, l);
    // if(l == 3)
    //     case_of_3(stack, l);
    // if(l == 4)
    //     case_of_4(stack,stackb, l);
    int pan = 0;
    int pbn = 0;

    // case_of_3(stack,l);
    // if(l == 2)
    //     case_of_2(stack, l);
    // if(l == 3)
    //     case_of_3(stack, l);
    // if(l == 4)
    //     case_of_4(stack, stackb, l, 0);
    // if(l == 5)
    //     case_of_5(stack,stackb, l);
    finish(stack, stackb,l);
    // ft_printf("%d",quit(stack, 1, l));
    // sort_check(stack, l);
    // ft_printf("%d",min_nbr(stack, l));
    // pb(stack, stackb, l, &pan);
    // printb(stackb, pbn, pan);

    //----------------//
}
#include <string.h>
int main(int argc, char **argv)
{
    int i = argc - 1;
    int *arg = malloc(i * sizeof(int));
    int j = 0;
    while(j < i)
    {
        arg[j] = ft_atoi(argv[j + 1]);
        j++;
    }
    va(i , arg);
}