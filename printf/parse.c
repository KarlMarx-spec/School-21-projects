/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/08 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_persicion3(t_list *t, char *line)
{
	if (*line >= '0' && *line <= '9')
	{
		t->max = ft_atoi(line);
		t->flag_pr = 1;
	}
	else if (t->flag_pr && t->max < 0)
	{
		t->flagmin = 1;
		t->max = 0;
	}
}

void	ft_check_persicion2(t_list *t, va_list ap)
{
	t->max = va_arg(ap, int);
	t->flag_pr = 1;
	if (t->max < 0)
	{
		t->max = -1;
		t->flag_pr = 0;
	}
}

int		ft_check_persicion(t_list *t, char **line, va_list ap)
{
	if (*line && **line == '.')
	{
		*line += 1;
		if (**line == '*')
			ft_check_persicion2(t, ap);
		else if (**line == '-')
		{
			t->flag_pr = 0;
			t->max = -1;
			*line += 1;
			while (**line >= '0' && **line <= '9')
				*line += 1;
		}
		else if (**line >= '0' && **line <= '9')
			ft_check_persicion3(t, *line);
		else
		{
			t->max = 0;
			t->flag_pr = 1;
		}
		while (**line && (**line == '*' ||
		(**line >= '0' && **line <= '9')))
			*line += 1;
	}
	return (0);
}

int		ft_check_flags(t_list *t, char **line)
{
	char *str;

	str = *line;
	if (str)
	{
		while (*str && (*str == '0' || *str == '-'))
		{
			if (*str == '0')
				t->flag0 = 1;
			if (*str == '-')
				t->flagmin = 1;
			str++;
		}
		*line = str;
		return (0);
	}
	else
		return (1);
}
