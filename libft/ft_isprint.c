/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:41:14 by wfeijoa           #+#    #+#             */
/*   Updated: 2020/09/22 18:46:27 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_isprint(int ch)
{
	if ((ch < 32) || (ch > 126))
		return (0);
	return (1);
}
