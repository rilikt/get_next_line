/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/26 16:56:01 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *store_string(char *str, char *buffer)
{
	int len = ft_strlen(buffer);

}

char	*get_next_line(int fd)
{
	static int bytes_read;
	static int i = 0;
	static int j = 0;
	char *buffer;
	static char *str;
	static int first_call = 0;

	if (first_call == 0)
	{
		str = ft_calloc(1, 1);
		first_call = 1;
	}

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	str = ft_strjoin(str, buffer);
	j = i;

	while (bytes_read != 0)
	{
		while (str[i] && str[i] != '\n')
		{
			i++;
		}
		if (str[i] != '\n')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			str = ft_strjoin(str, buffer);
		}
		if (str[i] == '\n')
		{
			i++;
			free (buffer);
			return (ft_substr(str, j, i-j));
		}
	}
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	free (buffer);
	return (ft_substr(str, j, i-j));
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

	char *str = get_next_line(fd);
	printf("return str: %s", str);
	str = get_next_line(fd);
	printf("return str: %s", str);
	str = get_next_line(fd);
	printf("return str: %s", str);

	close(fd);
	return (0);
}