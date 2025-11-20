/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:07:42 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/20 18:54:19 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(char **stock, char **line, int fd, int *sz)
{
	int	len;

	free(*stock);
	(*stock) = (*line);
	len = ft_strlen((*stock));
	(*line) = ft_calloc(sizeof(char) , BUFFER_SIZE + len + 1);
	if (!(*line))
	{
		free(*stock);
		return (0);
	}
	(*sz) = read(fd, (*line) + len, BUFFER_SIZE);
	if ((*sz) < 0)
	{
		free((*line));
		return (0);
	}
	fill_str((*stock), (*line));
	return (1);
}

int	check_sz(char **stock, char **line, char **p, int *sz)
{
	if (*sz == 0)
	{
		if ((*stock) && (*stock)[0] == '\0')
		{
			free(*stock);
			*stock = NULL;
		}
		free(*line);
		*p = NULL;
		return (0);
	}
	return (1);
}

int	check_readed_line(char **line, char **stock, int *sz, char **p)
{
	int	i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == '\n')
		{
			(*p) = ft_strdup((*line) + i + 1);
			if (!(*p))
			{
				free((*line));
				return (0);
			}
			(*line)[i + 1] = '\0';
			free((*stock));
			return (1);
		}
	}
	if (!check_sz(stock, line, p, sz))
		return (2);
	return (-1);
}

char	*get_next_line(int fd)
{
	int		sz;
	int		check;
	char 	*line;
	char	*stock;
	static char	*p = NULL;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	sz = BUFFER_SIZE;
	line = p;
	stock = NULL;
	while (sz != 0)
	{
		if (!read_file(&stock, &line, fd, &sz))
			return (NULL);
		check = check_readed_line(&line, &stock, &sz, &p);
		if (check == 2)
			return (stock);
		if (check == 0)
			return (0);
		else if (check == 1)
			return (line);
	}
	return (line);
}

