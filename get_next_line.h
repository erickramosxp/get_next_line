/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:27:51 by erramos           #+#    #+#             */
/*   Updated: 2023/11/23 15:06:18 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

void check_leaks();
char	*get_next_line(int fd);
size_t  ft_strlen(const char *s);
void    *ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlcat(char *dest, char *src, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
char     *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);

#endif
