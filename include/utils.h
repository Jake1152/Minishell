/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:45:28 by jim               #+#    #+#             */
/*   Updated: 2022/07/26 14:58:02 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# define SHELL_NAME "minishell"

int		is_whitespace(char const ch);
int		ft_is_alpha(int ch);
int		ft_is_digit(int ch);

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

void	ft_putstr_fd(const char *s, int fd);
void	print_newline_fd(int fd);

int		free_list(char ***word_list);
char	**ft_split(char const *s, char c);

char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, int len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

size_t	max_nonnegative(char const *s1, char const *s2);
int		split_key_value(char *envp_element, char **key, char **value);
int     free_key_value(char **key, char **value);

int		check_valid_name(char *str);
int     *get_exit_status();
void	safe_free(char	**char_pptr);

#endif
