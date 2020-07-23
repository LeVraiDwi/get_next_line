/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:07:15 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/23 16:00:14 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *str, char *buf, int len)
{
	int		i;
	int		l;
	char	*tmp;

	tmp = str;
	if (!(str = malloc(sizeof(char) * (len + ft_strlen(str) + 1))))
	{
		if (tmp)
			free(tmp);
		return (0);
	}
	i = 0;
	l = 0;
	if (tmp)
		while (tmp[i])
			str[l++] = tmp[i++];
	i = 0;
	while (len--)
		str[l++] = buf[i++];
	str[l] = 0;
	free(tmp);
	return (str);
}

int		ft_read(char **str, char *buf, int fd)
{
	int	len;

	if ((len = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	buf[len] = 0;
	if (len)
		if (!(*str = ft_strcat(*str, buf, len)))
			return (-1);
	return (len);
}

int		make_line(int fd, char **str, char *buf, char **line)
{
	int	len;
	int	l;

	l = is_line(*str);
	if ((len = ft_read(str, buf, fd)) == -1)
		return (ft_error(buf, *str, *line));
	free(buf);
	if (!(*line = ft_substr(*str, 0, l - 1)))
		return (ft_error(*str, buf, *line));
	buf = *str;
	if (!(*str = ft_substr(*str, l, ft_strlen(*str) - 1)))
		return (ft_error(*str, buf, *line));
	free(buf);
	if (!**str && !len)
	{
		free(*str);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			len;
	int			l;

	if (BUFFER_SIZE == 0 || !line)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ft_error(str, buf, *line));
	while (1)
	{
		if ((len = ft_read(&str, buf, fd)) == -1)
			return (ft_error(buf, str, *line));
		if ((l = is_line(str)) != -1)
			return (make_line(fd, &str, buf, line));
		else if (!str && !len)
		{
			free(buf);
			if (!(*line = ft_substr("", 0, 1)))
				return (ft_error(buf, str, *line));
			return (0);
		}
	}
}
