/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/26 15:51:31 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i = 0;
	char	*str;
	static int	index = 0;
	static int	prev_index = 0;
	int			read_return;
	
	if (!(fd >= 0))
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE * sizeof(char));
	read_return = read(fd, str, BUFFER_SIZE);
	// printf("read retturn: %d\n", read_return);
	if (read_return == -1 || str == NULL || read_return == 0)
	{
		free(str);
		// printf("entered return null\n");
		return (NULL);
	}
	if (!str[prev_index])
	{
		free(str);
		return (NULL);
	}
	
	while (index < BUFFER_SIZE)
	{
		if (str[index] == '\n' || str[index] == '\0')
			break;
		index++;
	}
	char *restr = (char *)malloc(index - prev_index * sizeof(char));
	if (restr == NULL)
		return (NULL);
	while (i + prev_index < index)
	{
		restr[i] = str[i];
		i++;
	}
	free(str);
	index++;
	prev_index = index;
	return (restr);
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	printf("\n----\nFD: %d\nBUFFER_SIZE: %d\n----\n\n", fd, BUFFER_SIZE);

// 	char *str = get_next_line(fd);
// 	printf("return str: %s", str);
// 	str = get_next_line(fd);
// 	printf("return str: %s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);

// 	close(fd);
// 	return (0);
// }