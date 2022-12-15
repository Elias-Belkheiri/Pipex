/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:33:20 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/12/15 12:21:38 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exit_error(int status)
{
    if (WIFEXITED(status))
        exit(WEXITSTATUS(status));
}

char    **get_paths(char **env)
{
    int i;

    i = 0;
	if (!env)
		return (NULL);
    while (ft_strncmp("PATH", env[i], 4))
        i++;
    return (ft_split(env[i] + 5, ':'));
}

void	ft_free_all_mfs(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void    trim(char **args)
{
    char    *tmp;
    
    free(*args);
    *args = ft_strdup("./pipex");
    tmp = ft_strtrim(args[1], "\"");
    free(args[1]);
    args[1] = tmp;
}

void    run_cmd(char **args, char **env, char **paths)
{
    char    *cmd;
    char    *path;

    cmd = ft_strjoin("/", *args);
    trim(args);
    path = ft_strjoin(*paths++, cmd);
    while (access(path, X_OK) && path)
    {
        free(path);
        path = ft_strjoin(*paths++, cmd);
    }
    if (!access(path, X_OK))
    {
        if (execve(path, args, env) == -1)
        {
            free(path);
            free(cmd);
            perror("EXECVE FAILED: ");
        }
    }
    fprintf(stderr, "pipex: %s: command not found\n", cmd + 1);
    exit(EXIT_FAILURE);
}

int	write_to_pipe(int fd[], int in, char  **args, char **env)
{
	pid_t	proc;
    int     status;
	char	**paths;
	
    status = 0;
	paths = get_paths(env);
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
        wait(&status);
    }
    return (status);
}

int	read_from_pipe(int fd[], int out, char  **args, char **env)
{
	pid_t	proc;
    int     status;
	char	**paths;
	
    status = 0;
	proc = fork();
	paths = get_paths(env);
	if (proc < 0)
    {
        perror("FORK FAILED: ");
        exit(EXIT_FAILURE);
    }
    else if (!proc)
    {
        close(fd[1]);
        dup2(fd[0], 0);
        dup2(out, 1);
        run_cmd(args, env, paths);
    }
    else
    {
        close(fd[0]);
        wait(&status);
    }
    return (status);
}

char **splitt(char *str)
{
    if (strchr(str, '\'') || strchr(str, '"'))
        return (ft_split_pipe(str, ' '));
    return (ft_split(str, ' '));
}

int main(int argc, char *argv[], char *env[])
{
    int     io[2];
    int     status;
    int		pipe_[2];
	char	**args1;
	char	**args2;

	if (argc < 5)
	{
		fprintf(stderr, "NOT ENOUGH ARGS\n");
		exit(EXIT_FAILURE);
	}
    io[0] = open(argv[1], O_RDONLY);
    io[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
    pipe(pipe_);
    if (io[0] < 0)
    {
        fprintf(stderr, "pipex: %s: %s\n", argv[1], strerror(errno));
        args2 = splitt(argv[3]);
        close(pipe_[1]);
        status = read_from_pipe(pipe_, io[1], args2, env);
        exit(0);
    }
	args1 = splitt(argv[2]);
	args2 = splitt(argv[3]);
    status = write_to_pipe(pipe_, io[0], args1, env);
	status = read_from_pipe(pipe_, io[1], args2, env);
	ft_free_all_mfs(args1);
	ft_free_all_mfs(args2);
	
}
