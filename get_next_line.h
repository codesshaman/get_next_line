/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:12:16 by jleslee           #+#    #+#             */
/*   Updated: 2021/11/24 18:40:03 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# define BUFFSIZE 3

int		ft_strlchr(char *str, char ch);
char	*ft_new_strjoin(char *str, char *ch);

typedef struct t_structure
{
	char	buf[BUFFSIZE + 1];
	char	*new_str_pointer;
	char	*str;
	int		read_bytes;
	int		flag;
}			t_struct;

#endif
