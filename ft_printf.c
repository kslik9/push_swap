/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:04:41 by kslik             #+#    #+#             */
/*   Updated: 2022/12/01 10:12:34 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//---------//
int	number(long int nb)
{
	int	p;
	int	sign;

	p = 0;
	sign = 1;
	p = p + count(nb);
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
		number(nb);
		p = 1 + count(nb);
	}
	else if (nb > 9)
	{
		number(nb / 10);
		number(nb % 10);
	}
	else if (nb <= 9)
		ft_putchar(nb + '0');
	return (p);
}

//-----------//
int	count(long int c)
{
	int	i;

	i = 0;
	if (c == 0)
		i = 1;
	while (c >= 1)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

//--------------------//
int	positive_nmb(unsigned int nb)
{
	int	c;

	c = count(nb);
	if (nb > 9)
	{
		number(nb / 10);
		number(nb % 10);
	}
	else if (nb <= 9)
		ft_putchar(nb + '0');
	return (c);
}

/////////-------------------------------------/////
int	mining(const char *l, va_list groupi)
{
	int	c;

	c = 0;
	if (*(l + 1) == '%')
		c = c + ft_putchar(37);
	else if (*(l + 1) == 'c')
		c = c + ft_putchar(va_arg(groupi, int));
	else if (*(l + 1) == 's')
		c = c + writeline(va_arg(groupi, char *));
	else if (*(l + 1) == 'd' || *(l + 1) == 'i')
		c = c + number(va_arg(groupi, int));
	else if (*(l + 1) == 'x')
		c = c + m_hexa(va_arg(groupi, int));
	else if (*(l + 1) == 'X')
		c = c + u_hexa(va_arg(groupi, long int));
	else if (*(l + 1) == 'u')
		c = c + positive_nmb(va_arg(groupi, int));
	else if (*(l + 1) == 'p')
		c = c + ad_hexa(va_arg(groupi, unsigned long));
	return (c);
}

/////////-------------------------------------/////
int	ft_printf(const char *l, ...)
{
	int	numbering;

	numbering = 0;
	va_list(groupi);
	va_start(groupi, l);
	while (*l)
	{
		if (*l == '%')
		{
			numbering = numbering + mining(l, groupi);
			l = l + 2;
		}
		else
		{
			write(1, &*l, 1);
			l++;
			numbering++;
		}
	}
	va_end(groupi);
	return (numbering);
}
