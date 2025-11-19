/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:23:43 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/19 15:55:36 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
size_t	ft_strlen(const char *s);
char	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar(char c);
char	*str_cat(char *src1, char *add, size_t size);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *src, char *dst, size_t size);
void	fill_str(char *src, char *dst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
#endif
