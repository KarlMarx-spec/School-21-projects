/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:58:18 by wfeijoa           #+#    #+#             */
/*   Updated: 2020/09/22 19:01:29 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int e)
{
	if (e < 0)
		return (0);
	return (-1);
}

int			ft_atoi(const char *s)
{
	long long	n;
	int			e;
	long long	tmp;

	n = 0;
	e = 1;
	while ((*s >= 7 && *s <= 13) || (*s == 32))
		s++;
	if ((*s == '+') || (*s == '-'))
	{
		if (*s == '-')
			e = -e;
		s++;
	}
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		tmp = n;
		n = n * 10 + *s++ - '0';
		if (tmp > n)
			return (check(e));
	}
	n *= e;
	return (n);
}
