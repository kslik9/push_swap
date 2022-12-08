/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:05:43 by kslik             #+#    #+#             */
/*   Updated: 2022/12/01 11:34:07 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *l, ...);
int		mining(const char *l, va_list groupi);
int		positive_nmb(unsigned int nb);
int		count(long int c);
int		number(long int nb);
int		ft_putchar(int c);
int		ad_hexa(unsigned long i);
int		u_hexa(unsigned int i);
int		m_hexa(unsigned int i);
int		hexo(long int i);
int		writeline(char *s);
char	*calloci(size_t i);
#endif