/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:51:39 by xcarroll          #+#    #+#             */
/*   Updated: 2022/11/20 16:53:41 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* for malloc and all that */
# include <stdlib.h>
/* for write() and read() */
# include <unistd.h>

/* define the buffer */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_clean_line(char *line);
char	*ft_clean_static_line(char *line);
#endif
