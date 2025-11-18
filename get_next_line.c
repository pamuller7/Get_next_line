/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:07:42 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/18 16:05:26 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		sz;
	int		i;
	char 	*line;
	char	*stock;
	static char	*p = 0;

	i = 0;
	if (fd < 0)
		return (0);
	sz = BUFFER_SIZE;
	line = p;
	while (sz == BUFFER_SIZE)
	{
		stock = line;
		line = ft_calloc(sizeof(char), BUFFER_SIZE + 1 + ft_strlen(stock));
		if (!line)
			return (0);
		sz = read(fd, line + ft_strlen(stock), BUFFER_SIZE);
		fill_str(stock, line);
		if (!line)
			return (0);
		i = 0;
		while (line[i++])
		{
			if (line[i] == '\n')
			{
				p = ft_strdup(line + i + 1);
				if (!p)
					return (0);
				line[i + 1] = '\0';
				return (line);
			}
		}
	}
	return (line);
}
// char	*get_next_line(int fd)
// {
// 	int		sz;
// 	int		i;
// 	char 	*line;
// 	char	*stock;
// 	static char	*p = 0;

// 	i = 0;
// 	if (fd < 0)
// 		return (0);
// 	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 4096)
// 		return (0);
// 	sz = BUFFER_SIZE;
// 	line = p;
// 	while (sz != 0)
// 	{
// 		stock = line;
// 		line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
// 		if (!line)
// 			return (0);
// 		sz = read(fd, line, BUFFER_SIZE);
// 		line = str_cat(stock, line, BUFFER_SIZE);
// 		if (!line)
// 			return (0);
// 		i = 0;
// 		while (line[i])
// 		{
// 			if (line[i] == '\n')
// 			{
// 				p = ft_strdup(line + i + 1);
// 				if (!p)
// 					return (0);
// 				line[i + 1] = '\0';
// 				return (line);
// 			}
// 			i++;
// 		}
// 	}
// 	return (line);
// }

// int	main(int ac, char**av)
// {
// 	int	fd;
// 	char *line;

// 	(void) ac;
// 	fd = open(av[1], O_RDONLY);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close (fd);
// }