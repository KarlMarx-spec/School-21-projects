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

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;
	size_t	i;

	count = 0;
	if (src == NULL)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && (size - i - 1))
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
	}
	while (src[count] != '\0')
		count++;
	return (count);
}
