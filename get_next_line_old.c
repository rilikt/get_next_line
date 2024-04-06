/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:01:14 by timschmi          #+#    #+#             */
/*   Updated: 2024/04/06 17:15:07 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_str(char *str, int i)
{
	int len = ft_strlen(str);

	if (len - i <= 0)
	{
		free (str);
		return (NULL);
	}
	else 
		return (str);
}

char	*get_next_line(int fd)
{
	static int bytes_read = 1;
	static int i = 0;
	static int j = 0;
	char *buffer;
	static char *str = NULL;
	char *restr;

	// printf("|beginning: %d |", bytes_read);

	if (bytes_read < 0)
		bytes_read = 1;

	// printf("|after cond: %d |", bytes_read);
	

	if (fd < 0 || BUFFER_SIZE <= 0 || (bytes_read == 0 && str == NULL))
		return (NULL);

	if (!str)
		str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	
	j = i;

	while (bytes_read != 0 && !(ft_strrchr(str + i, '\n')))
	{
		buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{	
			// printf("|x|entered -1 condition|x|");
			i = 0;
			j = 0;
			free (str);
			str = NULL;
			free (buffer);
			return (NULL);
		}
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}

	// printf("|after loop: %d |", bytes_read);

	
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	
	restr = ft_substr(str, j, i - j);

	if (!restr)
	{
		str = NULL;
		return (NULL);
	}

	if (bytes_read == 0)
		str = check_str(str, i);

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