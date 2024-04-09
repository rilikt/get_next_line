/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/09 15:40:55 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str)
{
	char		*buffer;
	static int	bytes_read = 1;
	static int	err = 0;

	if (err == 1 && bytes_read == 0)
	{
		bytes_read = 1;
		err = 0;
	}
	if (!str && bytes_read != 0)
		str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	while (bytes_read != 0 && !(ft_strrchr(str, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(str);
			err = 1;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	return (str);
}

char	*grab_line(char *str)
{
	int		i;
	char	*return_str;

	i = 0;
	if (!str[i])
	{
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	return_str = ft_substr(str, 0, i + 1);
	return (return_str);
}

char	*store_remaining(char *str)
{
	int		i;
	char	*return_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	return_str = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	return (return_str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_file(fd, str);
	if (!str)
		return (NULL);
	return_str = grab_line(str);
	str = store_remaining(str);
	return (return_str);
}

// int	main(void)
// {
// 	int fd = open("1char.txt", O_RDONLY);
// 	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

// 	char *str = get_next_line(fd);
// 	printf("return (str1: %s", str));
// 	str = get_next_line(fd);
// 	printf("return (str2: %s", str));
// 	str = get_next_line(fd);
// 	printf("return (str3: %s", str));
// 	str = get_next_line(fd);
// 	printf("return (str4: %s", str));
// 	// str = get_next_line(fd);
// 	// printf("return (str5: %s", str));

// 	free(str);
// 	close(fd);

// 	return (0);
// }