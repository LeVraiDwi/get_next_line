/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:16:39 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/27 19:49:11 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int	fd;
	int i;
	char **str;

	str = malloc(sizeof(char*));
	fd = open("text.txt", O_RDONLY);
/*	char *buf;
	buf = malloc(sizeof(char) * 17);
	printf("%zd\n", read(fd, buf, 1));
	printf("%zd\n", read(fd, buf, 1));
	free(buf);*/
	i = 1;
	*str = 0;
	while(i > 0)
	{
		i = get_next_line(fd, str);
		printf("%s ===> %d\n", *str, i);
		if(*str)
			free(*str);
		*str = 0;
	}
	printf("===================================================================================================\n");
	close(fd);
	free(str);
	return (0);
}
