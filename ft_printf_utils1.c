/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:28:16 by kslik             #+#    #+#             */
/*   Updated: 2022/12/09 10:40:13 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//----------------------------//
int	u_hexa(unsigned int i)
{
	int				k;
	unsigned int	r;
	unsigned int	b;
	char			t;
	char			*h;

	k = 0;
	r = i;
	k = hexo(i);
	i = k;
	h = calloci(k + 1);
	while (k > 0)
	{
		b = r % 16;
		r = r / 16;
		t = b + 48;
		if (b > 9)
			t = b + 55;
		h[k - 1] = t;
		k--;
	}
	writeline(h);
	free(h);
	return (i);
}

//---------------------------//
int	longerror(unsigned long int i)
{
	if (i == -9223372036854775808uLL)
	{
		write(1, "0x8000000000000000", 18);
		return (18);
	}
	if (i == 18446744073709551615uLL)
	{
		write(1, "0xffffffffffffffff", 18);
		return (18);
	}
	return (0);
}

//----------------------------//
int	ad_hexa(unsigned long i)
{
	int				k;
	unsigned long	r;
	unsigned long	b;
	char			t;
	char			*h;

	r = i;
	if (longerror(r) != 0)
		return (18);
	k = hexo(i);
	write(1, "0x", 2);
	i = k + 2;
	h = calloci(k + 1);
	while (k > 0)
	{
		b = r % 16;
		r = r / 16;
		t = b + 48;
		if (b > 9)
			t = b + 87;
		h[k-- - 1] = t;
	}
	writeline(h);
	free(h);
	return (i);
}

int	hexo(long int i)
{
	int	k;

	k = 0;
	if (i < 0)
		i = i * (-1);
	if (i == 0)
		k = 1;
	while (i > 0)
	{
		i = i / 16;
		k++;
	}
	return (k);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	alam;
	int	n;

	i = 0;
	alam = 1;
	n = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			alam = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n * alam);
}