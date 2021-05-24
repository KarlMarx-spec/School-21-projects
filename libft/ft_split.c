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
#include <stdlib.h>

static int		kolsl(char const *s, char c)
{
	int		i;
	int		kol;

	kol = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			kol++;
		i++;
	}
	return (kol);
}

static int		wlen(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		*leak(char **str, int kol)
{
	int	i;

	i = 0;
	while (i < kol)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char		**ft_spl(char const *s, char c, int kol, char **str)
{
	int	i;
	int	j;
	int	dl;

	i = -1;
	while (++i < kol)
	{
		while (*s == c)
			s++;
		dl = wlen(s, c);
		if (!(str[i] = (char*)malloc(sizeof(char) * (dl + 1))))
			return (leak(str, i));
		j = 0;
		while (j < dl)
			str[i][j++] = *s++;
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		kol;
	char	**str;

	if (!s)
		return (NULL);
	kol = kolsl(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (kol + 1))))
		return (NULL);
	str = ft_spl(s, c, kol, str);
	return (str);
}
