/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:09:54 by kslik             #+#    #+#             */
/*   Updated: 2022/12/22 15:06:03 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "ft_printf.h"
#include <stdlib.h>
#include <stdlib.h>
void finish(int *stack, int *stackb , int l);
void min_to_top5(int *stack, int l, int pbn);
int mn(int *stack, int l, int m);
int quit(int *stack, int pbn,int l);
void case_of_5(int *stack, int *stackb, int l);
void case_of_2(int *stack, int l);
void case_of_4(int *stack, int *stackb, int l, int m);
void min_to_top(int *stack, int l, int pbn, int m);
void case_of_3(int *stack, int l);
int min_nbr(int *stack, int pbn);
void printa(int *stack, int l, int pbn, int pan);
void printb(int *stack,int pbn, int pan);
void rb(int *stackb, int pbn);
void pb(int *stack,int *stackb, int l, int *pbn);
void ra(int *stack, int l,int pbn);
void rrb(int *stackb, int pbn);
void rra(int *stack, int l, int pbn);
void rrr(int *stack, int *stackb, int l, int pbn);
void rr(int *stack, int l, int pbn, int *stackb);
void pa(int *stack,int *stackb, int pbn, int l, int *pan);
int sb1(int *stackb, int l);
int sb(int *stackb, int l);
void sa(int *stack, int l, int pbn);
void sa1(int *stack, int l, int m);
void ss(int *stack, int *stackb, int l);
void va(int l, int *arr);
int check(int *stack, int l);

#endif