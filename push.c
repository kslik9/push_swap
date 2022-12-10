/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:09:56 by kslik             #+#    #+#             */
/*   Updated: 2022/12/09 19:04:08 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <stdlib.h>
void printa(int *stack, int l)
{
    
    int i = 0;
    while(i < l)
    {
        ft_printf("%d\n", stack[i]);
        i++;
    }
    ft_printf("\n-\na\n");
}
void printb(int *stack, int l)
{
  
    int i = l - 1;
    while(i >= 0)
    {
        ft_printf("%d\n", stack[i]);
        i--;
    }
    ft_printf("\n-\nb\n");
}
void pb(int *stack,int *stackb,int l)
{
    int i = 0;
    static int b = 0;

    stackb[b] = stack[0];

    b++;
    while(i < l - b)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[l - 1] = '\0';
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
    int pbn;
    int stackb[l];
    int count = 0;
    while(count < l)
    {
        stack[count] = arr[count];
        count++;
    }
    //----------------//
    // sa(stack, 3);
    // sort(stack, l);
    // sa(stack,l);
    pb(stack,stackb, l);
    pb(stack,stackb, l);
    pbn = 2;
    ss(stack,stackb, pbn);
    printa(stack, l - pbn);
    printb(stackb, pbn);
    // sb(stackb , 3);
    

    // print(stackb, 2);

    //----------------//
}
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