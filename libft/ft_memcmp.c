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

int		ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *(unsigned char*)mem1 == *(unsigned char*)mem2)
	{
		mem1 = (unsigned char*)mem1 + 1;
		mem2 = (unsigned char*)mem2 + 1;
	}
	return (*((unsigned char*)mem1) - *((unsigned char*)mem2));
}
