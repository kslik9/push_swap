/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:09:56 by kslik             #+#    #+#             */
/*   Updated: 2022/12/12 20:33:13 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <stdlib.h>
void printa(int *stack, int l, int pbn, int pan)
{
    int m = l - pbn - 1 + pan;
    while(m >= 0)
    {
        ft_printf("%d\n",stack[m]);
        m--;
    }
    ft_printf("\n-\na\n");
}
void printb(int *stack,int pbn, int pan)
{
  
    int m = pbn - pan - 1;
    while(m >= 0)
    {
        ft_printf("%d\n",stack[m]);
        m--;
    }
    ft_printf("\n-\nb\n");
}

void rb(int *stackb, int pbn)
{
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
    if(!stack[0])
        exit(0);
    static int m = 1;
    int topa = l - m;
    static int topb = 0;
    stackb[topb] = stack[topa];
    stack[topa] = '\0';
    m++;
    topb++;
    (*pbn)++;
}
void ra(int *stack, int l,int pbn)
{
    int i;
    i = 0;
    int m;
    m = l - pbn;
    stack[m] = stack[0];
    while(i < m)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[m] = '\0';
}
void rrb(int *stackb, int pbn)
{
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
    int m ;
    int i = l - pbn;
    int tmp[0];
    tmp[0] = stack[i - 1];
    m = i - 1;
    while(m > 0)
    {
        stack[m] = stack[m - 1];
        m--;
    }
    stack[0] = tmp[0];
    stack[i] = '\0';
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
    if(!stack[0] || !stackb[0])
        exit(0);
    static int m = 1;
    int topb = pbn - m;
    static int b = 0;
    int topa = l - pbn - b;
    stack[topa] = stackb[topb];
    stackb[topb] = '\0';
    m++;
    b--;
    (*pan)++;
}
int sb1(int *stackb, int l)
{
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
    ft_printf("Exec sb\n");
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
void sa(int *stack, int l)
{
   
    ft_printf("Exec sa\n");
    int i = 0;
    int tmp[1];
    if(l >= 1)
    {
        tmp[0] = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp[0];
    }
}
void sa1(int *stack, int l, int m)
{
   
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
void va(int l, int *arr)
{
    int stack[l];
    int pbn = 0;
    int stackb[l];
    int count = 0;
    int pan = 0;
    while(count < l)
    {
        stack[count] = arr[count];
        count++;
    }
    //----------------//

    // ra(stack, l, pbn);
    pb(stack, stackb, l, &pbn);
    pb(stack, stackb, l, &pbn);
    pb(stack, stackb, l, &pbn);
    pb(stack, stackb, l, &pbn);

    rrr(stack, stackb, l, pbn);
    
    // pb(stack, stackb, l, &pan);
    printa(stack, l, pbn, pan);
    printb(stackb, pbn, pan);
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