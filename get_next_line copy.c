/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/26 14:57:21 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	static char	*str;
	static int	index = 0;
	static int prev_index = 0;
	static int first_call = 0;
	int read_return;
	static int calls = 0;

	calls++;
	if (!(fd >= 0))
	{
		return (NULL);
	}

	if (first_call == 0)
	{
		str = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (str == NULL)
			return (NULL);
		read_return = read(fd, str, BUFFER_SIZE);
		if (str == NULL)
		{
			free(str);
			return (NULL);
		}
		if (read_return == -1)
		{
			free(str);
			return (NULL);
		}
		if (str[0] == '\0')
		{
			free(str);
			return (NULL);
		}
		first_call = 1;
	}

	// printf("string read:\n%s\n", str);
	// printf("index at the start: %d\n", index);
	i = 0;
	if (calls >= BUFFER_SIZE)
		return (NULL);
	while (str[index] && index < BUFFER_SIZE)
	{
		if (str[index] == '\n')
			break;
		index++;
	}
	// printf("index after first loop: %d\n", index);
	char *restr = (char *)malloc(index - prev_index * sizeof(char));
	while (i + prev_index <= index)
	{
		restr[i] = str[i + prev_index];
		i++;
	}
	// printf("index after second loop: %d\n", index);
	index++;
	prev_index = index;
	// printf("prev_index: %d\n", prev_index);
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
// 	// str = get_next_line(fd);
// 	// printf("%s", str);

// 	close(fd);
// 	return (0);
// }