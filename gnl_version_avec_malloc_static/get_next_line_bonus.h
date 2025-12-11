/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:23:43 by pamuller          #+#    #+#             */
/*   Updated: 2025/12/03 15:06:18 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define FD_MAX 1023
# define NO_ALLOC -1
# define ENDLINE_FOUND 1
# define END_OF_FILE 2

size_t	ft_strlen(const char *s);
char	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
void	fill_str(char *src, char *dst);
char	*realloc_line(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif
