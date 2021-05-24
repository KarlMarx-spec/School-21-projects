/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/06 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s = (char*)malloc((sizeof(*s1) + sizeof(*s2)) * (len + 1))))
		return (NULL);
	while (s1 && s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	if (s1)
		free(s1);
	return (s);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	if (str)
	{
		while (*str != '\0')
		{
			n++;
			str++;
		}
	}
	return (n);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	char	*i;
	int		j;

	dup = (char*)malloc(ft_strlen(s1) + 1);
	i = dup;
	if (dup == NULL)
		return (NULL);
	j = 0;
	while (s1[j])
		*i++ = s1[j++];
	*i = '\0';
	if (s1)
		free(s1);
	return (dup);
}
