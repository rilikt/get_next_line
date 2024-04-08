/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/08 17:00:57 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_file (int fd, char *str)
{
	char *buffer;
	static int bytes_read = 1;
	static int err = 0;

	if (err == 1 && bytes_read == 0)
	{
		bytes_read = 1;
		err = 0;
	}

		// printf("entered read\n");
	// printf("bytes read: %d ", bytes_read);
	
	if (!str && bytes_read != 0)
		str = ft_calloc(1, 1); // maybe move this
	if (!str)
		return (NULL);

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	while (bytes_read > 0 && !(ft_strrchr(str, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{	
			// printf("entered -1 ");

			free (buffer);
			free(str);
			bytes_read = 1;
			err++;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	// printf("bytes read: %d ", bytes_read);

	free (buffer);
	// printf("after read and join: %s ", str);

	return (str);
}

char *grab_line(char *str)
{
	// printf("entered grab line: %s\n", str);

	int i = 0;
	char *return_str;

	// printf("entered grab\n");

	if (!str[i])
	{
		// free(str);
		return (NULL);
	}


	while(str[i] && str[i] != '\n')
		i++;


	// printf("beofre substr\n");

	return_str = ft_substr(str, 0, i + 1);
	// printf("after substr\n");

	// if (return_str == NULL)
	// 	return (NULL);
	return (return_str);
}

char *store_remaining(char *str)
{
	// printf("entered store: %s ", str);

	int i = 0;
	char *return_str;

	// printf("entered store ");


	while(str[i] && str[i] != '\n')
		i++;

	if (!str[i])
	{
		free(str);
		return (NULL);
	}

	i++;
	return_str = ft_substr(str, i, ft_strlen(str) - i);
	free (str);
	// printf("remaining chars: %s ", return_str);
	return(return_str);
}

char	*get_next_line(int fd)
{
	static char *str = NULL;
	char *return_str;

	if (fd < 0 || BUFFER_SIZE <= 0) // || read(fd, 0, 0) < 0
	{
		if (str)
		{
			free (str);
			str = NULL;
		}
		return (NULL);
	}	
	
	// printf("str: %s ", str);

	str = ft_read_file(fd, str);
	if (!str)
	{
		// printf("entered cond ");

		free (str);
		return (NULL);
	}

	
	return_str = grab_line(str);
	// if (!return_str)
	// {	
	// 	return (NULL);
	// }
	
	str = store_remaining(str);
	// if (!str)
	// 	return (NULL);

		
	return (return_str);
}

// int	main(void)
// {
// 	int fd = open("1char.txt", O_RDONLY);
// 	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

// 	char *str = get_next_line(fd);
// 	printf("return str1: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str2: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str3: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str4: %s", str);
// 	// str = get_next_line(fd);
// 	// printf("return str5: %s", str);

// 	free(str);
// 	close(fd);
	
// 	return (0);
// }