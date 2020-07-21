/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:07:15 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/21 18:06:08 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *str, char *buf, int len)
{
	int		i;
	int		l;
	char	*tmp;

	if (str)
	{
		tmp = str;
		if (!(str = malloc(sizeof(char) * (len + ft_strlen(str) + 1))))
		{
			free(tmp);
			return (0);
		}
		i = 0;
		l = 0;
		while (tmp[i])
			str[l++] = tmp[i++];
		i = 0;
		while (buf[i])
			str[l++] = buf[i++];
		str[l] = 0;
		free(tmp);
		return (str);
	}
	else
	{
		free(str);
		return (buf);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			len;
	int			l;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ft_error(str, buf, *line));
	while (1)
	{	
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = 0;
		if (len)
			if(!(str = ft_strcat(str, buf, len)))
				return (ft_error(buf, str, *line));
		if ((l = is_line(str)) != -1)
		{
			if (buf != str)
				free(buf);
			if(!(*line = ft_substr(str, 0, l - 1)))
				return (ft_error(str, buf, *line));
			buf = str;
			if(!(str = ft_substr(str, l, ft_strlen(str) - 1)))
				return (ft_error(str, buf, *line));
			free(buf);
			if(!*str && !len)
			{
				free(str);
				return (0);
			}
			return (1);
		}
	}	
}
