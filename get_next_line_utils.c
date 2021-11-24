/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:34:43 by jleslee           #+#    #+#             */
/*   Updated: 2021/11/24 21:35:06 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// поиск первого вхождения
// символа ch в строке str

int	ft_strlchr(char *str, char ch)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	if (str[i] == ch)
		return (i);
	return (0);
}

char	*ft_new_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
    //free(s1);
	while (j < ft_strlen(s2))
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
    //free(s1);
	return (res);
}
