/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:03:59 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/19 18:18:20 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_cat(char *str, char *buf, int len)
{
	char	*tmp;
	int		i;
	int		l;
	
	printf("%d\n",8);
	tmp = str;
	printf("%d\najout: %s\n", 10, str);
	if(!(str = malloc(sizeof(char) * (len + ft_strlen(str) + 1))))
		return (0);
	i = 0;
	l = 0;
	printf("%d\n",9);
	while (tmp[i])
		str[l++] = tmp[i++];
	printf("%d\najout: %s\n", 10, str);
	i = 0;
	while (len--)
	{
		str[l++] = buf[i++];
	}
	str[l++] = 0;
	printf("%d\n",11);
	free(buf);
	free(tmp);
	return (1);
}

int read_line(char **str, char **line, int fd)
{
	char	*buf;
	int		len;
	
	printf("%d\n",5);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);
	if (!(len = read(fd, buf, BUFFER_SIZE)))
	{
		printf("%d\n",6);
		*line = *str;
		free(*str);
		return (-1);
	}
	buf[len - 1] = 0;
	printf("%d\n",7);
	if (str && *str && len)
	{
		printf("enter cat: %s \n", buf);
		if(!(ft_cat(*str, buf, len)))
			return (0);
	}
	else
		*str = buf;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *str;
	char		*buff;
	int			l;

	buff = 0;
	if (!line)
		return (ft_error(str, *line, buff));
	printf("%d\n",1);
	while (1)
	{
		l = is_line(str);
		printf("%d\n",2);
		if (str && *str && l != -1)
		{
			printf("%d\n",3);
			if (!(*line = ft_substr(str, 0, l - 1)))
				return (ft_error(str, *line, buff));
			buff = str;
			if (!(str = ft_substr(str, l + 1, ft_strlen(str)- l)))
				return (ft_error(str, *line, buff));
			free(buff);
			return (1);
		}
		printf("%d\n",4);
		if(!(l = read_line(&str, line, fd)))
			return (ft_error(str, *line, buff));
		else if (l == -1)
			return (0);
	}
}
