/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:07:42 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/19 16:43:24 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		sz;
	int		i;
	char 	*line;
	char	*stock;
	static char	*p = NULL;
	int		len;

	i = 0;
	if (fd < 0)
		return (0);
	if (BUFFER_SIZE == 0)
		return (0);
	sz = BUFFER_SIZE;
	line = p;
	stock = NULL;
	while (sz == BUFFER_SIZE)
	{
		
		stock = line;
		len = ft_strlen(line);
		line = ft_calloc(sizeof(char), BUFFER_SIZE + len + 1);
		if (!line)
			return (0);
		sz = read(fd, line + len, BUFFER_SIZE);
		if (sz < 0)
		{
			free(line);
			return (0);
		}
		fill_str(stock, line);
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
			{
				p = ft_strdup(line + i + 1);
				if (!p)
				{
					free(line);
					return (0);
				}
				line[i + 1] = '\0';
				free(stock);
				return (line);
			}
			i++;
		}
		if (sz == 0)
		{
			free(line);
			p = NULL;
			return (stock);
		}
		free(stock);
	}
	return (line);
}

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	char *line;
	int		i;

	i = 14;
	fd1 = open("txt1", O_RDONLY);
	fd2 = open("txt2", O_RDONLY);
	fd3 = open("txt3", O_RDONLY);
	fd4 = open("txt4", O_RDONLY);

	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	close (fd1);
	close (fd2);
	close(fd3);
	close(fd4);
}