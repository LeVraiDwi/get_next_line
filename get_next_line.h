/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:04:05 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/27 19:48:44 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		is_line(char *str);
int		ft_error(char *str, char *line, char *buf);
int		get_next_line(int fd, char **line);
int		ft_read(char **str, char *buf, int fd);
int		make_line(int fd, char **str, char *buf, char **line);
char	*ft_free(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcat(char *str, char *buf, int len);
size_t	ft_strlen(const char *str);
#endif
