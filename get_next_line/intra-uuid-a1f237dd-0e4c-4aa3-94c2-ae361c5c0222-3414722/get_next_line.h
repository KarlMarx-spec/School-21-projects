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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
char	*ft_strndup(char *s, char *res);
char	*ft_clear(char *s, char *res);
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s1);

#endif
