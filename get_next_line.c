/* ***********************************************\*************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:32:11 by erramos           #+#    #+#             */
/*   Updated: 2023/11/23 18:09:39 by erramos          ###   ########.fr       */
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
/*
void	ft_copy(char *line, char *temp)
{
	int	i;
	int	len;

	i = 0;
//	printf("%s\n\n", temp);
	len = ft_strlen(line);
	while (temp[i] != '\0')
	{
		line[len + i] = temp[i];
		i++;
	}
//	printf("%s\n\n", line);
}
*/
char	*convert(char *line, char *buff)
{
	char	*temp;

	if (!line)
	{
		line = ft_strdup(buff);
//		printf("%s", line);
	}
	else
	{
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, buff);
		free(temp);
	}
//	printf("\nTransferindo o buffer: %s para linha: %s\n", buff, line);
	return (line);
}
char	*new_line(char	*resp, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	resp = (char *)malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		resp[j] = line[j];
		j++;
	}
	resp[j] = '\0';
//	printf("\nNova linha: %s\n", resp);
	return (resp);
}

char	*remove_linebreak(char *line)
{
	int	i;
	int	j;
	char	*temp;

	i = 0;
	while (line[i] != '\n')
		i++;
	j = i;
	while (line[j] != '\0')
		j++;
	temp = ft_strdup(line);
	free(line);
	line = (char *)malloc((j - i + 1) * sizeof(char));
	i++;
	j = 0;
	while (temp[i] != '\0')
	{
		line[j] = temp[i];
		i++;
		j++;
	}
	if (temp[i] == '\0')
		line[j] = '\0';
//	printf("\nVariavel temporaria do remover quebra: %s\n", temp);
	free(temp);
//	printf("\nQuebra de linha removida: %s\n", line);
	return (line);
}
/*
char	*transfer(int fd, char *buff, char *line)
{
	char	*resp;
	int	rd;
	int	check;

	rd = 1;
	check = 1;
	while (rd > 0 && check)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		buff[rd] = '\0';
		line = convert(line, buff);
		if (check_backslash(line))
		{
			resp = new_line(resp, line);
//			line = remove_linebreak(line);
//			printf("\n\n%s\n\n", line);
			check = 0;
		}
	}
	return (resp);
}
*/
char	*get_next_line(int fd)
{
	char	*buff;
	static char	*line;
	char	*resp;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
//	resp = transfer(fd, buff, line);
//

//	char    *resp;
        int     rd;
        int     check;

        rd = 1;
        check = 1;
        while (rd > 0 && check)
        {
                rd = read(fd, buff, BUFFER_SIZE);
		if (rd == 0)
		{
//			free(line);
			free(buff);
			return (NULL);
		}
//		printf("\nbites lidos :%d\n", rd);
                buff[rd] = '\0';
                line = convert(line, buff);
                if (check_backslash(line))
                {
                        resp = new_line(resp, line);
                   	line = remove_linebreak(line);
//                      printf("\n\n%s\n\n", line);
                        check = 0;
                }
        }
	free(buff);
//	printf("\n\n%s\n\n", line);
//	printf("%s", line);
	return (resp);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
//	get_next_line(fd);
//	get_next_line(fd);
//	get_next_line(fd);
	printf("Primeira parte:\n%s",  get_next_line(fd));
	printf("\nsegunda parte:\n");
	printf("%s", get_next_line(fd));
	printf("\nterceira parte:\n");
	printf("%s", get_next_line(fd));
	printf("\n%s", get_next_line(fd));
//	close(fd);
}
