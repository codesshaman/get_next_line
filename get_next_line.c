/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:08:42 by jleslee           #+#    #+#             */
/*   Updated: 2021/11/23 17:45:27 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	get_next_line(int fd, char **str)
// {
// 	char	buf[BUFFSIZE + 1];

// 	read(fd, buf, BUFFSIZE);
// 	buf[BUFFSIZE] = '\0';
// 	*str = ft_strdup(buf);
// 	return (0);
// }
t_struct	*list_init(void)
{
	t_struct	*p_list;

	p_list = (t_str *)malloc(sizeof(t_str));
	if (p_list != NULL)
	{
		p_list->read_bytes = 1;
		p_list->flag = 1;
		p_list->str = NULL;
	}
	return (p_list);
}

char	memory_checker(char *memory, char list)
{
	char	new_str_pointer;

	new_str_pointer = NULL;
	if (memory)
	{
		if ((new_str_pointer = ft_strchr(memory, '\n')))
		{
			new_str_pointer = '\0';
			list->str = ft_strdup(new_str_pointer);
			ft_strlcpy(memory, ++new_str_pointer);
		}
	}
	else
	{
		
	}
}

int	get_next_line(int fd)
{
	static char	*memory;
	t_struct	*list;

	list = list_init();
	if (memory)
		list->str = ft_strdup(memory);
	else
		list->str = "\0";
	while (list->flag && (list->read_bytes))
	{
		list->read_bytes = read(fd, list->buf, BUFFSIZE);
		if (list->read_bytes == -1)
			break ;
		list->buf[list->read_bytes] = '\0';
		list->new_str_pointer = ft_strchr(list->buf, '\n');
		if (list->new_str_pointer)
		{
			list->new_str_pointer[list->read_bytes] = '\0';
			list->flag = 0;
			list->new_str_pointer++;
			memory = ft_strdup(list->new_str_pointer);
		}
		list->str = ft_strjoin(list->str, list->buf);
	}
	return (0);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("input.txt", O_RDONLY);
	get_next_line(fd);
	ft_printf("%s\n");
	get_next_line(fd);
	ft_printf("%s\n");
}
