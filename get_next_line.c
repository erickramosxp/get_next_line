/* ***********************************************\*************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:32:11 by erramos           #+#    #+#             */
/*   Updated: 2023/11/27 16:54:36 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int	check_breakline(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
static char	*read_line(int fd, char *rest, char *buffer)
{
	int	rd;
	char	*temp;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (0);
		if (rd == 0)
			break;
		buffer[rd] = '\0';
		if (!rest)
			rest = ft_strdup("");
		temp = ft_strdup(rest);
		free(rest);
		rest = ft_strjoin(temp, buffer);
//		free(temp);
//		free(buffer);
//		temp = NULL;
		if (check_breakline(rest))
			break;
	}
	return (rest);
}

static char	*get_line(char *line, char *rest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	while (j <= i)
	{
		line[j] = rest[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*remove_breakline(char *rest)
{
	char	*temp;
	int	i;
	int	j;

	i = 0;
	if (!rest)
		return (0);
	while(rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (rest[i] == '\0')
		return (0);
	j = i;
	while (rest[j] != '\0')
		j++;
	temp = ft_strdup(rest);
	free(rest);
	rest = (char *)malloc((j - i + 1) * sizeof(char));
	i++;
	j = 0;
	while (temp[i] != '\0')
	{
		rest[j] = temp[i];
		j++;
		i++;
	}
//	if (temp[i] == '\0')
	rest[j] = '\0';
	free(temp);
	temp = NULL;
	if (rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
	}
	return (rest);
}

char    *get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	static char	*rest;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	rest = read_line(fd, rest, buffer);
	free(buffer);
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	line = get_line(line, rest);
	rest = remove_breakline(rest);
/*	if (rest[0] == '\0')
        {
                free(rest);
                return (NULL);
        }*/
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
//	get_next_line(fd);
//	get_next_line(fd);
//	get_next_line(fd);

	char	*a = get_next_line(fd);
	printf("Primeira parte:\n%s", a);
	free(a);
	printf("\nsegunda parte:\n");
	char    *b = get_next_line(fd);
	printf("%s", b);
	free(b);
	printf("\nterceira parte:\n");
	char    *c = get_next_line(fd);
	printf("%s", c);
	free(c);
	char    *d = get_next_line(fd);
	printf("\n%s", d);
	free(d);
	char    *e = get_next_line(fd);
	printf("\n%s", e);
	free(e);
	char    *f = get_next_line(fd);
	printf("\n%s", f);
	free(f);
	char    *h = get_next_line(fd);
	printf("\n%s", h);
	free(h);
	printf("\n%s", get_next_line(fd));
	printf("\n%s\n\n", get_next_line(fd));
//	close(fd);
}*/
