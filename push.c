/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:09:56 by kslik             #+#    #+#             */
/*   Updated: 2022/12/08 19:30:51 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
void sa(int *stack, int l)
{
    ft_printf("Exec sa\n");
    int i = 0;
    int tmp[1];
    tmp[0] = stack[0];
    stack[0] = stack[1];
    stack[1] = tmp[0];
    i = 0;
    while(i < l)
    {
        ft_printf("%d\n" ,stack[i]);
        i++;
    }
    ft_printf("\n-\na");

}
void sort(int *stack, int l)
{
    int i = 0;
    int tmp[1];
    int m = l;
    while(m >= 0)
    {
        i = l - 1;
        while(i > 0)
        {
            if(stack[i - 1] < stack[i])
            {
                tmp[0] = stack[i];
                stack[i] = stack[i - 1];
                stack[i - 1] = tmp[0];
            }
            i--;
        }
        m--;
    }
    i = 0;
    // while (i < l)
    // {
    //     printf("%d ", stack[i]);
    //     i++;
    // }
}
void va(int l, int *arr)
{
    int stack[l];
    int count = 0;
    while(count < l)
    {
        stack[count] = arr[count];
        count++;
    }
    //----------------//
    sa(stack, l);
    //sort(stack, l);
    //----------------//
}
int main(int argc, char **argv)
{
    int i = argc - 1;
    int *arg = malloc(i * sizeof(int));
    int j = 0;
    while(j < i)
    {
        arg[j] = atoi(argv[j + 1]);
        j++;
    }
    va(i , arg);
}