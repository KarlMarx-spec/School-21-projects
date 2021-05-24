/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/08 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		check(int e)
{
	if (e < 0)
		return (0);
	return (-1);
}

static int		ft_len(long long n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len = 11;
	else if (n == 2147483648)
		len = 10;
	else
	{
		if (n <= 0)
		{
			len++;
			n *= -1;
		}
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

static char		*ft_dop(char *s, int len, long long j)
{
	s[len] = '\0';
	len--;
	if (j == 0)
		s[0] = '0';
	while (j > 0)
	{
		s[len] = j % 10 + '0';
		j = j / 10;
		len--;
	}
	if (j > 0)
		s[len] = j % 10 + '0';
	return (s);
}

char			*ft_itoa(long long n)
{
	int			len;
	char		*s;
	long long	j;

	j = n;
	len = ft_len(j);
	if (!(s = (char*)malloc(len + 1)))
		return (NULL);
	if (j < 0)
	{
		s[0] = '-';
		j *= -1;
	}
	s = ft_dop(s, len, j);
	return (s);
}

int				ft_atoi(char *s)
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
