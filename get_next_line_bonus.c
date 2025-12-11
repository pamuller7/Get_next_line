/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:07:42 by pamuller          #+#    #+#             */
/*   Updated: 2025/12/11 11:54:34 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_file(char **stock, char **line, int fd, int *sz)
{
	int	len;

	(*stock) = ft_strdup(*line);
	if (*line)
		free(*line);
	len = ft_strlen((*stock));
	(*line) = ft_calloc(sizeof(char), BUFFER_SIZE + len + 1);
	if (!(*line))
	{
		free(*stock);
		return (0);
	}
	(*sz) = read(fd, (*line) + len, BUFFER_SIZE);
	if ((*sz) < 0)
	{
		free(*line);
		free(*stock);
		return (0);
	}
	fill_str((*stock), (*line));
	return (1);
}

static int	check_sz(char **stock, char **line, int *sz)
{
	if (*sz == 0)
	{
		if ((*stock) && (*stock)[0] == '\0')
		{
			free(*stock);
			*stock = NULL;
		}
		free(*line);
		return (0);
	}
	return (1);
}

static int	check_readed_line(char **line, char **stock, int *sz, char *p)
{
	int	i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == '\n')
		{
			p = ft_strcpy(p, (*line) + i + 1);
			(*line)[i + 1] = '\0';
			return (ENDLINE_FOUND);
		}
	}
	p[0] = '\0';
	if (!check_sz(stock, line, sz))
		return (END_OF_FILE);
	return (0);
}

static char	*reinit_p(char *p)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		p[i] = '\0';
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			sz;
	int			check;
	char		*line;
	char		*stock;
	static char	p[1024][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (0);
	sz = BUFFER_SIZE;
	line = ft_strdup(p[fd]);
	if (!line)
		return (0);
	stock = NULL;
	while (sz != 0)
	{
		if (!read_file(&stock, &line, fd, &sz))
			return (reinit_p(p[fd]));
		check = check_readed_line(&line, &stock, &sz, (p[fd]));
		if (check == END_OF_FILE)
			return (stock);
		free(stock);
		if (check == ENDLINE_FOUND)
			return (line);
	}
	return (0);
}
