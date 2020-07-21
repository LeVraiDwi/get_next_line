/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:16:39 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/20 15:56:55 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	int i;
	char **str;

	str = malloc(sizeof(char*));
	fd = open("text.txt", O_RDONLY);
	i = 1;
	while(i)
	{
		i = get_next_line(fd, str);
		printf("%s ====> %d\n", *str, i);
		free(*str);
	}
	close(fd);
	free(str);
}
