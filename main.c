/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:25:47 by dbessa            #+#    #+#             */
/*   Updated: 2023/11/17 09:28:42 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	int		fd;
	char	*imprime;
	int		i;

	i = 0;
	fd = open("lorem.txt", O_RDWR);
	while (i < 6)
	{
		imprime = get_next_line(fd);
		printf("%s", imprime);
                free(imprime);
		i++;
	}
	close (fd);
	return (0);
}
