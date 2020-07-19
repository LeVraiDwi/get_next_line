/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:04:13 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/19 18:20:33 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (*str++)
		c++;
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s || start > (unsigned int)ft_strlen(s) || len == 0)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s += start;
	while (len-- && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		is_line(char *str)
{
	int	i;

	if (!str)
		return(-1);
	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return(i);
	return (-1);
}

int		ft_error(char *str, char *line, char *buf)
{
	if (str)
		free(str);
	if (line)
		free(line);
	if (buf)
		free(buf);
	return (-1);
}
