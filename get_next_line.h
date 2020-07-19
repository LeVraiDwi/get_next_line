/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:04:05 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/19 17:13:52 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     is_line(char *str);
int     ft_error(char *str, char *line, char *buf);
int		get_next_line(int fd, char **line);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *str);
#endif
