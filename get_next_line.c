/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:32:11 by erramos           #+#    #+#             */
/*   Updated: 2023/11/20 20:42:06 by erramos          ###   ########.fr       */
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
                        return (0);
                i++;
        }
        return (1);
}

char	*transfer(char *line, char *buff, int size, int *check)
{
	char	*fund_back;
	char	*temp;
	int	i;
	int	len;

	if (!line)
	{
		line = (char *)malloc(size * sizeof(char));
		ft_memmove(line, buff, size);
	}
	else
	{
		temp = ft_strdup(line);
		free(line);
		line = (char *)malloc(size * sizeof(char));

	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	static char	*buffer;
	int	rd;
	int	check;

	rd = 1;
	check = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE + 1] = '\0';
	while (rd > 0 && check)
	{
		rd += read(fd, buff, BUFFER_SIZE);
		line = transfer(line, buff, rd, &check);
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
