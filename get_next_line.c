/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:03:59 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/17 16:02:11 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *str;
	char		*buff;
	int			l;

	buff = 0;
	if (!line)
		return (ft_error(str, *line, buff));
	l = is_line(str);
	while (1)
	{
		if (*str && l != -1)
		{
			if (!(*line = ft_substr(str, 0, l - 1)))
				return (ft_error(str, *line, buff));
			buff = str;
			if (!(str = ft_substr(str, l + 1, ft_strlen(str)- l - 1)))
				return (ft_error(str, *line, buff));
			free(buff);
			return (1);
		}
		else
		{
			if(!(buff = malloc(sizeof(char) * BUFFER_SIZE)))
				return (ft_error(str, *line, buff));
			if(!(read(fd, buff, BUFFER_SIZE)))
			{
				*line = str;
				free(str);
				free(buff);
				return (0);
			}
		}
	}
}
