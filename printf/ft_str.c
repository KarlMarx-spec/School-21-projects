/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/08 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_str4(char *str, int n, int len)
{
	int x;

	x = 0;
	while (n < len)
	{
		ft_putchar(str[n]);
		n++;
		x++;
	}
	return (x);
}

int			ft_str3(t_list *t, int *len)
{
	int	n;

	n = 0;
	while (t->min - *len > 0)
	{
		if (t->flag0 == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		t->min--;
		n++;
	}
	return (n);
}

int			ft_str(t_list *t, char *str)
{
	int		len;
	int		n;
	int		count;

	n = 0;
	count = 0;
	len = ft_strlen(str);
	if (len == 0)
		str = NULL;
	if (len > t->max && t->max >= 0)
		len = t->max;
	if (t->flagmin == 1)
	{
		count += ft_str4(str, n, len);
		count += ft_str3(t, &len);
	}
	else
	{
		count += ft_str3(t, &len);
		count += ft_str4(str, n, len);
	}
	return (count);
}

int			ft_str2(t_list *t, char *str)
{
	if (str == NULL)
	{
		return (ft_str(t, "(null)"));
	}
	else
	{
		return (ft_str(t, str));
	}
}
