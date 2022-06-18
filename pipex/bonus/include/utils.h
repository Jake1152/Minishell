/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:01 by jim               #+#    #+#             */
/*   Updated: 2022/06/18 18:35:02 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);

int		free_list(char ***word_list);
char	**ft_split(char const *s, char c);

char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_itoa(int n);
char	*ft_gnl_strjoin(char *s1, char *s2);

size_t	max_nonnegative(char const *s1, char const *s2);

#endif
