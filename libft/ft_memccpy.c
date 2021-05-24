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

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*dest;
	unsigned char		*src;
	size_t				i;

	i = 0;
	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	while (i < n)
	{
		dest[i] = src[i];
		if (dest[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}
