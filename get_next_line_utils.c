/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:12:59 by erramos           #+#    #+#             */
/*   Updated: 2023/11/17 19:46:16 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	size_dest;
	size_t	total_size;
	size_t	j;

	j = 0;
	size_dest = ft_strlen(dest);
	if (size_dest >= n)
		return (n + ft_strlen(src));
	while (src[j] != '\0' && size_dest < n - 1)
	{
		dest[size_dest] = src[j];
		size_dest++;
		j++;
	}
	dest[size_dest] = '\0';
	total_size = size_dest + ft_strlen(src) - j;
	return (total_size);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	i;

	dest2 = (char *)dest;
	src2 = (char *)src;
	if (!dest2 && !src2)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	if (!dest2 && !src2)
		return (NULL);
	if (dest2 > src2)
	{
		dest2 = dest2 + (n - 1);
		src2 = src2 + (n - 1);
		while (n)
		{
			*dest2-- = *src2--;
			n--;
		}
	}
	else
		ft_memcpy(dest2, src2, n);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*news;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	news = (char *)malloc((len + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	ft_memmove(news, (char *)s1, len + 1);
	ft_strlcat(news, (char *)s2, len + 1);
	news[len] = '\0';
	return (news);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strcpy(copy, s);
	return (copy);
}
