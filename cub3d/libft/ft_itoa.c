/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <wfeijoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:42:42 by wfeijoa           #+#    #+#             */
/*   Updated: 2020/11/23 18:45:05 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len = 11;
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

char			*ft_itoa(int n)
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
