/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/06 12:00:35 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_str(char *str, int i)
{
	int len = ft_strlen(str);

	if (len - i <= 0)
		return (0);
	else 
		return (1);
}

char	*get_next_line(int fd)
{
	int bytes_read = 1;
	int i = 0;
	char *buffer;
	char *str = NULL;
	char *restr;
	// static char *store = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) > 0)
		return (NULL);

	if (!str)
		str = ft_calloc(1, 1);
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
			free (str);
			str = NULL;
			free (buffer);
			return (NULL);
		}
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}

	while (str[i] && str[i] != '\n')
		i++;

	restr = ft_substr(str, 0, i);

	if (!restr)
		return (NULL);
	if (restr[0] == '\0')
	{
		free(str);
		str = NULL;
		free(restr);
		return (NULL);
	}

	str = ft_substrr(str + i);
	if (!str)
		return (NULL);

	return (restr);
}

// int	main(void)
// {
// 	int fd = open("1char.txt", O_RDONLY);
// 	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

// 	char *str = get_next_line(fd);
// 	printf("return str1: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str2: %s", str);
// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("return str3: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str4: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str5: %s", str);

// 	free(str);
// 	close(fd);
	
// 	return (0);
// }