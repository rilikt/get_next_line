/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:06:50 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/03 15:01:44 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

extern char *get_next_line(int fd);
extern void	*ft_calloc(size_t num, size_t size);
extern void	ft_bzero(void *s, size_t n);
extern char	*ft_strjoin(char *s1, char *s2);
extern size_t	ft_strlcat(char *dest, const char *source, size_t size);
extern size_t	ft_strlen(const char *str);
extern char	*ft_substr(char *s, unsigned int start, size_t len, int bytes_read);
extern char	*ft_strrchr(const char *str, int c);




#endif