/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/25 15:37:05 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	line;
	char		c;
	int			i;
	char		*str;
	static int	bytes_read = 0;

	line = 0;
	c = 'c';
	i = 0;
	str = (char *)malloc(BUFFER_SIZE - bytes_read * sizeof(char));
	
	while (i < BUFFER_SIZE && bytes_read < BUFFER_SIZE)
	{
		bytes_read += read(fd, &str[i], 1);
		// printf("char %d: %c\n", i, str[i]);
		if (str[i] == '\n')
		{
			printf("bytes read: %d\n", bytes_read);
			return (str);
		}
		i++;
	}
	printf("Byte count till end of line: %d\n", i);
	// int check = read(fd, str, i);
	// if (check == 0)
	// 	printf("End of file has been reached.\n");
	// else if (check == -1)
	// 	printf("Error reading the file.\n");
	return (str);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

	char *str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);

	close(fd);
	return (0);
}