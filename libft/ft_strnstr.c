/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <wfeijoa@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 21:24:36 by wfeijoa           #+#    #+#             */
/*   Updated: 2020/09/19 21:26:47 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s2[i])
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		if (s1[i] == s2[n])
		{
			if (s2[n + 1] == '\0')
				return ((char *)s1 + i - n);
			i++;
			n++;
		}
		else
		{
			i = i - n + 1;
			n = 0;
		}
	}
	return (NULL);
}
