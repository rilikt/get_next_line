/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/06 18:33:16 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_file (int fd, char *str)
{
	char *buffer;
	int bytes_read = 1;
			
	if (!str)
		return (NULL);
	
	while (bytes_read != 0 && !(ft_strrchr(str, '\n')))
	{
		buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
		if (!buffer)
			return (NULL);
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
	return (str);
}

char *get_line(char *str)
{
	int i = 0;
	char *return_str;

	if (str[i] == '\0')
		return(NULL);
	while(str[i] && str[i] != '\n')
		i++;
	return_str = ft_substr(str, 0, i + 1);
	if (return_str == NULL)
		return (NULL);
	return (return_str);
}

char *store_remaining(char *str)
{
	int i = 0;
	char *return_str;

	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return(NULL);
	}
	i++;
	return_str = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	printf("remaining chars: %s ", return_str);
	return(return_str);
}

char	*get_next_line(int fd)
{
	static char *str = NULL;
	char *return_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
	if (!str)
		str = ft_calloc(1, 1); // maybe move this
	
	str = ft_read_file(fd, str);
	if (str == NULL)
		return (NULL);
	
	return_str = get_line(str);
	if (return_str == NULL)
		return (NULL);
	
	str = store_remaining(str);

	return (return_str);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

	char *str = get_next_line(fd);
	printf("return str1: %s", str);
	str = get_next_line(fd);
	printf("return str2: %s", str);
	str = get_next_line(fd);
	printf("return str3: %s", str);
	// str = get_next_line(fd);
	// printf("return str4: %s", str);
	// str = get_next_line(fd);
	// printf("return str5: %s", str);

	free(str);
	close(fd);
	
	return (0);
}