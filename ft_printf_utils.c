/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:20:24 by kslik             #+#    #+#             */
/*   Updated: 2022/12/01 10:17:57 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*calloci(size_t i)
{
	char	*p;
	size_t	k;

	k = 0;
	p = malloc(i);
	while (k < i)
	{
		p[k] = '\0';
		k++;
	}
	return (p);
}

//----------------------------//
int	writeline(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

//----------------------------//
int	m_hexa(unsigned int i)
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
			t = b + 87;
		h[k - 1] = t;
		k--;
	}
	writeline(h);
	free(h);
	return (i);
}
