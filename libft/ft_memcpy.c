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

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*dest;
	unsigned const char	*src;
	unsigned int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
