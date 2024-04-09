/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/09 14:46:06 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	int				n;

	n = num * size;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char				*sub;
	unsigned long int	i;
	unsigned int		size;
	unsigned int		str_len;

	i = 0;
	size = len;
	str_len = ft_strlen(s);
	if (start + len > str_len)
		size = str_len - start;
	if (start >= str_len)
		size = 0;
	if (size == 0)
		return (NULL);
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub[size] = '\0';
	while (s[start] && len > i && size != 0)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	return (sub);
}

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	*st;
	int		len;

	st = (char *)str;
	ch = (char)c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (ch == st[len])
			return (st + len);
		len--;
	}
	return (0);
}
