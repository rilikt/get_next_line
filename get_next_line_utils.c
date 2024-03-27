/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/27 15:17:56 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*str;

	total_len = ft_strlen(s1) + ft_strlen(s2) +1;
	str = (char *)ft_calloc(total_len, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, s1, total_len);
	ft_strlcat(str, s2, total_len);
	return (str);
}

size_t	ft_strlcat(char *dest, const char *source, size_t size)
{
	unsigned long int	dest_len;
	unsigned long int	source_len;
	unsigned long int	i;
	unsigned long int	n;

	dest_len = ft_strlen(dest);
	source_len = ft_strlen(source);
	i = 0;
	if (dest_len < size)
		n = dest_len + source_len;
	else
		n = source_len + size;
	while (source[i] && (dest_len + i) < size - 1 && size != 0)
	{
		dest[dest_len + i] = source[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (n);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub[size] = '\0';
	if (size == 0)
		return (sub);
	while (s[start] && len > i && size != 0)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	return (sub);
}
