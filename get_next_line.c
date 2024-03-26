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

char	*get_next_line(int fd)
{
	int bytes_read = 1;
	int i = 0;
	int j = 0;
	char *str;

	if (fd < 0)
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE * sizeof(char));
	printf("str size: %lu\n", sizeof(str));
	bytes_read = read(fd, str, BUFFER_SIZE);
	if (bytes_read == -1 || str == NULL)
		return (NULL);
	if (bytes_read == 0) // end of the file has been reached
	{
		while(str[i])
		{
			if (str[i] == '\n')
				break;
			i++;
		}
	}
	char *temp = (char *)malloc(sizeof(str) * sizeof(char));
	while (str[j])
	{
		temp[j] = str[j];
		j++;
	}

	return (NULL);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

	char *str = get_next_line(fd);
	printf("return str: %s", str);
	// str = get_next_line(fd);
	// printf("return str: %s", str);
	// str = get_next_line(fd);
	// printf("%s", str);

	close(fd);
	return (0);
}