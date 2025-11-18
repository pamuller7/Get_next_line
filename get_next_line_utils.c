/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:11:27 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/18 15:56:21 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > 2147483647 / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	while (i < size * nmemb)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
char	*str_cat(char *src1, char *add, size_t size)
{
	int		i;
	int		j;
	char	*new_str;
	int		old_len;

	i = 0;
	j = 0;
	old_len = ft_strlen(src1);
	new_str = malloc(sizeof(char) * (old_len + size + 1));
	if (!new_str)
	{
		free(src1);
		return (0);
	}
	if (src1)
	{
		while (src1[i])
		{
			new_str[i] = src1[i];
			i++;
		}
	}
	if (add)
	{
		while (add[j])
		{
			new_str[i] = add[j];
			j++;
			i++;
		}
	}
	new_str[i] = '\0';
	free(add);
	free(src1);
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dup = malloc (sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	fill_str(char *src, char *dst)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	while (dst[i])
		i++;
	dst[i] = '\0';
	free(src);
}