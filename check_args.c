/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:06:23 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 16:04:14 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_from_si(int fd, char *limiter)
{
	char	*tmp;
	int		fd2;

	while (1)
	{
		tmp = get_next_line(0);
		if (!ft_strncmp(tmp, limiter, ft_strlen(tmp) - 1))
			break ;
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
	}
	if (tmp)
		free(tmp);
	close(fd);
	fd2 = open("/tmp/tmpfile", O_RDONLY);
	return (fd2);
}

int	check_args(int *fd, char **argv, int argc)
{
	if (!ft_strncmp("here_doc", argv[1], 8))
	{
		fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		fd[0] = open("/tmp/tmpfile", O_CREAT | O_RDWR | O_TRUNC, 0644);
		fd[0] = read_from_si(fd[0], argv[2]);
		return (1);
	}
	fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	fd[0] = open(argv[1], O_RDONLY);
	return (0);
}
