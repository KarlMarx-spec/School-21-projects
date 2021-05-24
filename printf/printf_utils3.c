/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/08 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_col(unsigned int n)
{
	int e;

	if (n == 0)
		return (1);
	e = 0;
	while (n > 0)
	{
		n = n / 10;
		e++;
	}
	return (e);
}

int		ft_cold(t_list *t, int n)
{
	int e;

	if (t->max == 0)
		return (0);
	if (n == 0)
		return (1);
	e = 0;
	while (n > 0)
	{
		n = n / 10;
		e++;
	}
	return (e);
}

int		ft_char(t_list *t, char c)
{
	int		n;
	int		count;

	count = 0;
	n = t->min - 1;
	if (t->flagmin == 1)
		write(1, &c, 1);
	while (n > 0)
	{
		if (t->flag0 == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
		n--;
	}
	if (t->flagmin != 1)
		write(1, &c, 1);
	count++;
	return (count);
}

int		ft_coli(unsigned long n, int base)
{
	int e;

	if (n == 0)
		return (1);
	e = 0;
	while (n > 0)
	{
		n = n / base;
		e++;
	}
	return (e);
}

char	*ft_itoa_base(unsigned long n, int base, int type)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	i = ft_coli(n, base);
	if (!(nbr = (char*)malloc(sizeof(nbr) * i)))
		return (NULL);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (n % base);
		if (n % base > 9 && type)
			nbr[i + neg] += 'A' - 10;
		else if (n % base > 9)
			nbr[i + neg] += 'a' - 10;
		else
			nbr[i + neg] += '0';
		n = n / base;
	}
	return (nbr);
}
