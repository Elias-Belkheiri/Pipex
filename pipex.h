/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:55:21 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/04 12:50:17 by ebelkhei         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	**ft_split(char const *s, char c);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *ptr);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split_pipe(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**get_paths(char **env);
char	*gnl_ft_strjoin(char *str1, char *str2);
void	ft_free_all_mfs(char **str);
char	*gnl_ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);
size_t	get_len(char *str);
char	*get_next_line(int fd);
int		read_from_si(int fd, char *limiter);
int		check_args(int *fd, char **argv, int argc);
int		wait_free(char **paths, int in, pid_t PID);
int		pipex(int argc, char *argv[], char *env[], int io[]);
void	loop_to_wait(int i);
void	write_error_and_exit(void);

#endif