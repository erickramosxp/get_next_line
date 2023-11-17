/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:32:11 by erramos           #+#    #+#             */
/*   Updated: 2023/11/17 19:55:26 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*transfer(char *line, char *buff, int size)
{
	char	*temp;

	if (line == 0)
	{
		line = (char *)malloc(size * sizeof(char));
		if (!line)
			return (NULL);
		ft_memmove(line, buff, size);
	}
	else 
	{
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, buff);
		free(temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buff;
	static	char	*line;
	static	int	size;

	size += BUFFER_SIZE;
	buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	read(fd, buff, BUFFER_SIZE);
	line = transfer(line, buff, size);
	free(buff);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*new;

	fd = open("text.txt", O_RDONLY);
	new = get_next_line(fd);
	printf("Primeira parte:\n");
	printf("%s", new);
	printf("\nsegunda parte:\n");
	printf("%s", get_next_line(fd));
	printf("\nterceira parte:\n");
	printf("%s", get_next_line(fd));
}
