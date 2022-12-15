/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:55:21 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/12/15 11:27:44 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <sys/errno.h>

char	**ft_split(char const *s, char c);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *ptr);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char	**ft_split_pipe(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif