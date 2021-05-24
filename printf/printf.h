/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:07:38 by wfeijoa           #+#    #+#             */
/*   Updated: 2021/01/06 17:07:41 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_list
{
	int		min;
	int		max;
	short	flag0;
	short	flagmin;
	short	flag_wd;
	short	flag_pr;
	short	flag_otr;
}				t_list;

char			*ft_itoa(long long n);
char			*ft_itoa_base(unsigned long n, int base, int type);
int				ft_check_persicion(t_list *t, char **line, va_list ap);
int				ft_check_flags(t_list *t, char **line);
size_t			ft_strlen(const char *str);
int				ft_atoi(char *s);
int				ft_char(t_list *t, char c);
int				ft_digit(t_list *t, long n);
int				ft_uns(t_list *t, unsigned int n);
int				ft_point(t_list *t, unsigned long n);
int				ft_xout(t_list *t, unsigned int n, int type);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_str2(t_list *t, char *str);
char			*ft_strdup(char *s1);
int				ft_check_spec(t_list *t, char **line, va_list ap);

#endif
