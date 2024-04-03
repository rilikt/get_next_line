/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/03 15:56:44 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int ft_checks(int fd, int bytes_read)
// {

// }

char	*get_next_line(int fd)
{
	static int bytes_read = 1;
	static int i = 0;
	static int j = 0;
	char *buffer;
	static char *str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || bytes_read == 0)
		return (NULL);

	buffer = calloc(BUFFER_SIZE +1, sizeof(char));
	if (!buffer)
		return (NULL);
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	
	if (bytes_read <= 0)
	{	
		free (buffer);
		return (NULL);
	}

	if (!str)
		str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	
	str = ft_strjoin(str, buffer);
	if (!str)
		return (NULL);
	
	j = i;

	while (bytes_read != 0 && !(ft_strrchr(str + i, '\n')))
	{
		buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{	
			free (buffer);
			return (NULL);
		}
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}

	while (str[i] && str[i] != '\n')
		i++;
	i++;
	
	return (ft_substr(str, j, i - j, bytes_read));
}

// int	main(void)
// {
// 	int fd = open("1char.txt", O_RDONLY);
// 	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

// 	char *str = get_next_line(fd);
// 	printf("return str: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str: %s", str);

// 	str = get_next_line(fd);
// 	printf("return str: %s", str);
// 	free(str);


// 	close(fd);
// 	return (0);
// }