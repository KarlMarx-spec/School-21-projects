/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:06:55 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/06 17:07:15 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_strndup(char *s, char *res)
{
	char	*str;
	int		n;

	n = s - res;
	if (!(str = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	str[n--] = '\0';
	while (n >= 0)
	{
		str[n] = res[n];
		n--;
	}
	return (str);
}

char	*ft_clear(char *s, char *res)
{
	int		n;
	int		i;
	int		m;
	char	*str;

	n = ft_strlen(res) - (s - res) - 1;
	if (!(str = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	str[n] = '\0';
	m = 0;
	i = s - res + 1;
	while (m < n)
	{
		str[m] = res[i];
		m++;
		i++;
	}
	if (res)
		free(res);
	return (str);
}

int		ft_help(char **line, char **res, char **s)
{
	if ((*s = ft_strchr(*res, '\n')))
	{
		*line = ft_strndup(*s, *res);
		*res = ft_clear(*s, *res);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*res;
	char		*s;
	char		buff[BUFFER_SIZE + 1];
	size_t		count;

	if (fd < 0 || (read(fd, 0, 0) == -1) || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(s = NULL) && res && ft_help(line, &res, &s))
		return (1);
	while (1)
	{
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = '\0';
		if (!(res = ft_strjoin(res, buff)))
			return (-1);
		if (ft_help(line, &res, &s))
			return (1);
		if (count < BUFFER_SIZE)
		{
			*line = ft_strdup(res);
			res = NULL;
			return (0);
		}
	}
	return (-1);
}
