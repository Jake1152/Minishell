/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:10:59 by jim               #+#    #+#             */
/*   Updated: 2022/06/06 19:36:14 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "utils.h"

void	ft_putstr(char *s)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	write(1, s, str_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	s1_size;
	size_t	s2_size;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		s1 = ft_strdup("");
		if (s1 == NULL)
			return (NULL);
	}
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (dst == NULL)
	{
		free(s1);
		return (NULL);
	}	
	ft_strlcpy(dst, s1, s1_size + 1);
	free(s1);
	ft_strlcat(dst, s2, s1_size + s2_size + 1);
	return (dst);
}