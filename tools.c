/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:59:09 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/04 12:48:37 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all_mfs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	wait_free(char **paths, int in, pid_t PID)
{
	int	x;
	int	exit_status;

	exit_status = 0;
	if (PID)
	{
		waitpid(PID, &x, 0);
		if (WIFEXITED(x))
			exit_status = WEXITSTATUS(x);
	}
	close(in);
	ft_free_all_mfs(paths);
	return (exit_status);
}

void	loop_to_wait(int i)
{
	while (i--)
		wait(NULL);
}

void	write_error_and_exit(void)
{
	perror("");
	exit(EXIT_FAILURE);
}
