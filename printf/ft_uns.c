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

int		ft_max2(int len, int max)
{
	if (len >= max)
		return (len);
	return (max);
}

int		ft_uns2(t_list *t, char *s)
{
	int		count;
	int		len;

	count = 0;
	len = ft_strlen(s);
	if (t->flag_pr == 1)
		t->flag0 = 0;
	while (t->flagmin != 1 && t->min-- > ft_max2(len, t->max))
	{
		if (t->flag0 == 1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	while (t->max-- > len)
	{
		count += ft_putchar('0');
		t->min--;
	}
	count += ft_putstr(s);
	t->min -= len;
	while (t->flagmin == 1 && t->min-- > 0)
		count += ft_putchar(' ');
	return (count);
}

int		ft_uns(t_list *t, unsigned int n)
{
	char	*str;
	int		count;

	count = 0;
	if (n == 0 && t->flag_pr)
		str = ft_strdup("");
	else
		str = ft_itoa_base(n, 10, 1);
	count += ft_uns2(t, str);
	free(str);
	return (count);
}
