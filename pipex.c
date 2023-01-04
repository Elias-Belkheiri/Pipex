/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:27:58 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/04 12:50:11 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	run_cmd(char **args, char **env, char **paths)
{
	int		i;
	char	*cmd;
	char	*path;

	i = 0;
	cmd = ft_strjoin("/", *args);
	path = ft_strjoin(paths[i++], cmd);
	while (access(path, X_OK) && path)
	{
		free(path);
		path = ft_strjoin(paths[i++], cmd);
	}
	if (!access(path, X_OK))
	{
		if (execve(path, args, env) == -1)
		{
			free(path);
			free(cmd);
			perror("EXECVE FAILED: ");
		}
		exit(127);
	}
	write(2, "COOMAND NOT FOUND\n", ft_strlen("COOMAND NOT FOUND\n"));
	exit(127);
}

void	write_to_pipe(int in, char **args, char **env, int *i)
{
	pid_t	proc;
	int		fd[2];
	char	**paths;

	paths = get_paths(env);
	pipe(fd);
	proc = fork();
	if (proc < 0)
	{
		perror("FORK FAILED: ");
		exit(EXIT_FAILURE);
	}
	else if (!proc)
	{
		close(fd[0]);
		dup2(in, 0);
		dup2(fd[1], 1);
		run_cmd(args, env, paths);
	}
	else
	{
		close(fd[1]);
		wait_free(paths, in, 0);
	}
	*i = fd[0];
}

int	read_from_pipe(int in, int out, char **args, char **env)
{
	pid_t	proc;
	char	**paths;

	paths = get_paths(env);
	proc = fork();
	if (proc < 0)
	{
		perror("FORK FAILED: ");
		exit(EXIT_FAILURE);
	}
	else if (!proc)
	{
		dup2(in, 0);
		dup2(out, 1);
		run_cmd(args, env, paths);
	}
	else
		close(in);
	return (wait_free(paths, in, proc));
}

int	pipex(int argc, char *argv[], char *env[], int io[])
{
	int		bonus;
	int		i;
	int		in;
	int		exit_status;
	char	**cmd;

	bonus = check_args(io, argv, argc);
	if (io[0] < 0 || io[1] < 0)
		write_error_and_exit();
	i = -1;
	while (++i < argc - 3 - bonus)
	{
		cmd = ft_split(argv[i + 2 + bonus], ' ');
		if (!(i))
			write_to_pipe(io[0], cmd, env, &in);
		else if (i == argc - 4 - bonus)
		{
			exit_status = read_from_pipe(in, io[1], cmd, env);
			loop_to_wait(argc - 4 - bonus);
		}
		else
			write_to_pipe(in, cmd, env, &in);
		ft_free_all_mfs(cmd);
	}
	return (exit_status);
}
