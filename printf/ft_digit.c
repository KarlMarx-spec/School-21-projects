/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/08 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_put(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_maxd(int len, int max, int flag)
{
	if (flag && max > 0)
		max++;
	if (len >= max)
		return (len);
	return (max);
}

int		ft_outmin(t_list *t, int *flag, int *len, int *count)
{
	int n;

	n = 0;
	if (*flag)
	{
		*count += ft_put('-');
		*len -= 1;
		*flag = 0;
		t->min--;
		n = 1;
	}
	return (n);
}

int		ft_outdigit(t_list *t, char *str, int flag)
{
	int	count;
	int	len;

	len = ft_strlen(str);
	count = 0;
	if (t->flagmin != 1)
	{
		if (t->flag0 == 1 && t->flag_pr == 0)
			if (ft_outmin(t, &flag, &len, &count))
				str++;
		while (t->min-- > ft_maxd(len, t->max, flag))
			count += (t->flag0 && t->flag_pr == 0) ? ft_put('0') : ft_put(' ');
	}
	if (ft_outmin(t, &flag, &len, &count))
		str++;
	while (t->max-- > len && t->min-- != -2147483648)
		count += ft_put('0');
	t->min -= len;
	count += ft_putstr(str);
	while (t->min-- > 0 && t->flagmin == 1)
		count += ft_put(' ');
	return (count);
}

int		ft_digit(t_list *t, long n)
{
	int		count;
	char	*str;

	count = 0;
	if (n == 0 && t->max == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(n);
	if (n < 0)
		count += ft_outdigit(t, str, 1);
	else
		count += ft_outdigit(t, str, 0);
	free(str);
	return (count);
}
