/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/08 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_point_help(int pr, int len)
{
	if (pr == 0)
		return (2);
	if (pr < 0 || pr < len)
		return (len);
	return (pr);
}

int			ft_point_help2(t_list *t)
{
	int n;

	n = 0;
	ft_putchar(' ');
	n += 1;
	t->min--;
	return (n);
}

int			ft_point2(t_list *t, char *str)
{
	int		count;
	int		len;
	int		i;

	i = 0;
	count = 0;
	len = ft_strlen(str) + 2;
	if (t->flagmin != 1 && t->flag_wd == 1)
		while (t->min > ft_point_help(t->max, len))
			count += ft_point_help2(t);
	(count += ft_putstr("0x")) ? (len -= 2) : (len -= 0);
	while (t->max > len)
	{
		count += ft_putchar('0');
		t->max--;
	}
	while (t->flag_pr == 1 && t->max > 0 && str[i])
		count += ft_putchar(str[i++]);
	(t->flag_pr != 1) ? (count += ft_putstr(str)) : (t->flag_pr = 0);
	i = (i == 0) ? len : 0;
	t->min -= i + 2;
	if (t->flagmin)
		while (t->min > 0)
			count += ft_point_help2(t);
	return (count);
}

int			ft_point(t_list *t, unsigned long n)
{
	int		count;
	char	*str;

	str = ft_itoa_base(n, 16, 0);
	count = ft_point2(t, str);
	free(str);
	return (count);
}
