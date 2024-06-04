/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:41:36 by opanikov          #+#    #+#             */
/*   Updated: 2024/03/19 17:50:19 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new_line(char *tmp)
{
	int		i;
	char	*str;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_right_line(char *tmp)
{
	char	*new_tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	new_tmp = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!new_tmp)
		return (NULL);
	i++;
	while (tmp[i])
		new_tmp[j++] = tmp[i++];
	new_tmp[j] = '\0';
	free(tmp);
	return (new_tmp);
}

char	*ft_read(char *tmp, int fd)
{
	char	*buf;
	int		i;

	i = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (!ft_strchr(buf, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			free(tmp);
			tmp = NULL;
			buf = NULL;
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	tmp[fd] = ft_read(tmp[fd], fd);
	if (!tmp[fd])
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	str = ft_new_line(tmp[fd]);
	tmp[fd] = ft_right_line(tmp[fd]);
	return (str);
}

// #include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("cat.txt", O_RDONLY);
// 	fd2 = open("cat2.txt", O_RDONLY);
// 	fd3 = open("cat3.txt", O_RDONLY);
// 	printf("1 %s", get_next_line(fd1));
// 	printf("2 %s", get_next_line(fd2));
// 	printf("3 %s", get_next_line(fd1));
// 	printf("4 %s", get_next_line(fd2));
// 	printf("5 %s", get_next_line(fd3));
// 	printf("\n");
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// }
