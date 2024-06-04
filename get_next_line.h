/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:15:38 by opanikov          #+#    #+#             */
/*   Updated: 2024/03/17 20:28:53 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_new_line(char *tmp);
char	*ft_right_line(char *tmp);
char	*ft_read(char *tmp, int fd);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);

#endif
