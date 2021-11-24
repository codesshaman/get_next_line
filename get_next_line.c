/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:08:42 by jleslee           #+#    #+#             */
/*   Updated: 2021/11/24 21:37:18 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Читает строку до конца буфера

static char	*reader(int fd, char *str)
{
	char	*buff;
	int		readed_bytes;

	readed_bytes = 1;
	if (str == NULL)
		str = "";
	buff = malloc(BUFFSIZE + 1);
	if (!buff)
		return (0);
	while (!ft_strlchr(str, '\n') && readed_bytes > 0)
	{
		readed_bytes = read(fd, buff, BUFFSIZE);
		if (readed_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[readed_bytes] = '\0';
		str = ft_new_strjoin(str, buff);
		//free(str);
		//free(buff);
	}
	free(buff);
	return (str);
}

// Возвращает строку до \n

static char	*stringer(char *str)
{
	char	*buff;
	int		i;

	i = 0;
	//ft_printf("1=%s\n", str);
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buff[i] = str[i];
		i++;
	}
	//ft_printf("2=%s\n", buff);
	buff[i] = '\0';
	return (buff);
}

// Читает остаток в str

static char	*reminder(char *str)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	//ft_printf("=%s\n", str);
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (ft_strlen(str) - i < 1)
	{
		free(str);
		return (0);
	}
	//ft_printf("=%d\n%d", ft_strlen(str), i);
	buf = malloc(ft_strlen(str) - i + 1);
	if (!buf)
		return (0);
	while (i < ft_strlen(str))
	{
		buf[j++] = str[i++];
	}
	buf[j] = '\0';
	free(str);
	//ft_printf("++%s\n", str);
	return (buf);
}

// reader читает строку до конца буфера
// stringer выводит строку до \n
// reminder сохраняет остаток в str

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buff;

	if (str == NULL)
		str = "\0";
	if (fd < 0)
		return (0);
	// if (buff == NULL)
	// 	buff = "";
	str = reader(fd, str);
	//ft_printf("%s\n", str);
	buff = stringer(str);
	//ft_printf("==%s", buff);
	str = reminder(str);
	//ft_printf("==%s\n", str);
	return (buff);
}

int	main(void)
{
	int		fd;

	fd = open("input.txt", O_RDONLY);
	//ft_printf("%d\n", fd);
	//get_next_line(fd);
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
}
