/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:32:11 by erramos           #+#    #+#             */
/*   Updated: 2023/11/21 18:58:16 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int     check_backslash(char *buff)
{
	int	i;

	i = 0;
        while (buff[i] != '\0')
        {
                if (buff[i] == '\n')
                        return (1);
                i++;
        }
        return (0);
}

char	*transfer(char *line, char *buff, char *buffer, int size, int *check)
{
	char	*temp;
	int	i;
	int	j;
	int	len;


	i = 0;
	j = 0;
	ft_memmove(buffer, buff, size);
	len = ft_strlen(buffer);
	if (len > 0)
	{
		line = (char *)malloc(len * sizeof(char));
		ft_memmove(line, buffer, len);
		buffer = 0;
	}
	if (!line && !check_backslash(buffer))
	{
		line = (char *)malloc(size * sizeof(char));
		ft_memmove(line, buffer, size);
	}
	if (line && !check_backslash(buffer))
	{
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, buffer);
		free(temp);
	}
	else if (check_backslash(buffer))
	{
		len = ft_strlen(line);
		temp = ft_strdup(line);
		free(line);
		line = (char *)malloc((len + size) * sizeof(char));
		ft_strcpy(line, temp);
		free(temp);
		while (buffer[i] != '\n')
		{
			line[len + i] = buffer[i];
			i++;
		}
		i++;
		while (buffer[i] != '\0')
		{
			buffer[j] = buffer[i];
			i++;
			j++;
			buffer[j] = '\0';
			check = 0;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	static char	buffer[BUFFER_SIZE + 1];
	int	rd;
	int	check;

	rd = 1;
	check = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (rd > 0 && check)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		buff[rd] = '\0';
		line = transfer(line, buff, buffer, rd, &check);
	}
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("Primeira parte:\n%s",  get_next_line(fd));
	printf("\nsegunda parte:\n");
	printf("%s", get_next_line(fd));
//	printf("\nterceira parte:\n");
//	printf("%s", get_next_line(fd));
	close(fd);
}
