/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/27 15:29:46 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int ft_checks(int fd, int bytes_read)
// {

// }

char	*get_next_line(int fd)
{
	static int bytes_read = 0;
	static int i = 0;
	static int j = 0;
	char *buffer;
	static char *str;
	static int first_call = 0;
	char *restr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = calloc(BUFFER_SIZE +1, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1 || bytes_read == 0 || buffer == NULL)
	{	
		free (buffer);
		return (NULL);
	}

	if (first_call == 0)
	{
		str = ft_calloc(1, 1);
		first_call = 1;
	}
	
	str = ft_strjoin(str, buffer);
	free (buffer);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	j = i;

	while (bytes_read != 0)
	{
		while (str[i] && str[i] != '\n')
		{
			i++;
		}
		if (str[i] != '\n')
		{
			buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			str = ft_strjoin(str, buffer);
			free (buffer);
			if (str == NULL)
			{
				free (str);
				free (buffer);
				return (NULL);
			}
		}
		if (str[i] == '\n' || str[i] == '\0')
		{
			i++;
			return (ft_substr(str, j, i-j));
		}
	}

	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	restr = ft_substr(str, j, i-j -1);
	free(str);
	return (restr);
}

// int	main(void)
// {
// 	int fd = open("1char.txt", O_RDONLY);
// 	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

// 	char *str = get_next_line(fd);
// 	printf("return str: %s", str);
// 	// str = get_next_line(fd);
// 	// printf("return str: %s", str);
// 	// str = get_next_line(fd);
// 	// printf("return str: %s", str);

// 	close(fd);
// 	return (0);
// }