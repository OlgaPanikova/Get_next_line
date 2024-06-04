/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:55:44 by opanikov          #+#    #+#             */
/*   Updated: 2024/03/11 14:59:24 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_dest;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	str_dest = (char *)malloc(
			((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str_dest)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str_dest[i] = s1[i];
	while (s2[++j] != '\0')
		str_dest[i + j] = s2[j];
	str_dest[i + j] = '\0';
	free(s1);
	return (str_dest);
}
