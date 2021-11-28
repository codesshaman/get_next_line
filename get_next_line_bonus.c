/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:14:28 by jleslee           #+#    #+#             */
/*   Updated: 2021/11/26 23:58:34 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Удаляет лишнее

char	*cutting(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	buff = malloc (sizeof(char) * (ft_strlen(str) - i + 1));
	if (!buff)
		return (0);
	j = 0;
	i++;
	while (str[i])
	{
		buff[j++] = str[i++];
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

// Возвращает строку + \0

char	*new_line(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (0);
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
	buff[i] = '\0';
	return (buff);
}

// Читает весь текст в static

static char	*reader(int fd, char *str)
{
	char	*buff;
	int		readed_bytes;

	readed_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!line_num(str) && readed_bytes != 0)
	{
		readed_bytes = read(fd, buff, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[readed_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = reader(fd, str[fd]);
	if (!str[fd])
		return (0);
	buff = new_line(str[fd]);
	str[fd] = cutting(str[fd]);
	return (buff);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int		fd[5];
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;

// 	fd[1] = open("Tsiolkovsky.txt", O_RDONLY);
// 	s1 = get_next_line(fd[1]);
// 	printf("%s\n",s1);
// 	fd[1] = open("Jukovsky.txt", O_RDONLY);
// 	s2 = get_next_line(fd[1]);
// 	printf("%s\n",s2);
// 	fd[2] = open("Mendeleev.txt", O_RDONLY);
// 	s3 = get_next_line(fd[2]);
// 	printf("%s",s3);
// }
