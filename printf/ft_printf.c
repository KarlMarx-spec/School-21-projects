/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:10:11 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/08 17:10:14 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_spec(t_list *t, char **line, va_list ap)
{
	if (*line)
	{
		if (t->flag0 == 1 && t->flagmin == 1)
			t->flag0 = 0;
		if (**line == 'd' || **line == 'i')
			return (ft_digit(t, va_arg(ap, int)));
		if (**line == 'u')
			return (ft_uns(t, va_arg(ap, unsigned int)));
		if (**line == 'c')
			return (ft_char(t, va_arg(ap, int)));
		if (**line == 'p')
			return (ft_point(t, va_arg(ap, unsigned long)));
		if (**line == 's')
			return (ft_str2(t, va_arg(ap, char*)));
		if (**line == 'x')
			return (ft_xout(t, va_arg(ap, unsigned int), 0));
		if (**line == 'X')
			return (ft_xout(t, va_arg(ap, unsigned int), 1));
		if (**line == '%')
			return (ft_char(t, '%'));
		return (-1);
	}
	return (-1);
}

int		ft_check_width(t_list *t, char **line, va_list ap)
{
	if (*line)
	{
		if (**line == '*')
		{
			t->min = va_arg(ap, int);
			if (t->min < 0)
			{
				t->flagmin = 1;
				t->min *= -1;
			}
			t->flag_wd = 1;
		}
		else if (**line >= '0' && **line <= '9')
		{
			t->min = ft_atoi(*line);
			t->flag_wd = 1;
		}
		while (**line && (**line == '*' ||
		(**line >= '0' && **line <= '9')))
			*line += 1;
		return (0);
	}
	return (1);
}

int		parse(t_list *t, char **line, va_list ap)
{
	t->flag0 = 0;
	t->flagmin = 0;
	t->flag_otr = 0;
	t->flag_pr = 0;
	t->flag_wd = 0;
	t->max = -1;
	t->min = 0;
	if (ft_check_flags(t, line))
		return (-1);
	if (ft_check_width(t, line, ap))
		return (-1);
	if (ft_check_persicion(t, line, ap))
		return (-1);
	return (ft_check_spec(t, line, ap));
}

int		ft_printf(char *line, ...)
{
	int		i;
	int		count;
	int		tmp;
	t_list	t;
	va_list ap;

	va_start(ap, line);
	count = 0;
	i = 0;
	while (*line)
	{
		if (*line == '%')
		{
			line++;
			if ((tmp = parse(&t, &line, ap)) != -1)
				count += tmp;
			else
				break ;
		}
		else
			count += write(1, line, 1);
		line++;
	}
	va_end(ap);
	return (count);
}
