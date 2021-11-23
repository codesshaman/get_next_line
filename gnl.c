/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:57:37 by jleslee           #+#    #+#             */
/*   Updated: 2021/11/23 19:42:31 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	reader(int fd, char *str)
{
	char	buff[BUFFSIZE + 1];
	int		readed_bytes;

	str = "\0";
	read(fd, buff, BUFFSIZE);
	str = ft_strdup(buff);
	return (0);
}

int	get_next_line(int fd)
{
	char	*str;

	reader(fd, str);
	return (0);
}

int	main(void)
{
	int		fd;

	fd = open("input.txt", O_RDONLY);
	get_next_line(fd);
	ft_printf("%s\n");
	get_next_line(fd);
	ft_printf("%s\n");
}
