/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:33:20 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/12/12 19:53:53 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_paths(char **env)
{
    int i;

    i = 0;
    while (strncmp("PATH", env[i], 4))
        i++;
    return (ft_split(env[i] + 5, ':'));
}

/*

void    run_cmd(char **args, char **env, char **paths)
{
    char    *cmd;
    char    *path;

    cmd = ft_strjoin("/", *args);
    free(*args);
    *args = ft_strdup("./pipex");
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
            exit(EXIT_FAILURE);
        }
    }
    perror("ACCESS PROBLEME: ");
    exit(EXIT_FAILURE);
}

int pipex(int fd, char  **args, char **env, char **paths)
{
    int   pipe_[2];
    pid_t proc;
    
    pipe(pipe_);
    proc = fork();
    if (proc < 0)
    {
        perror("FORK FAILED: ");
        exit(EXIT_FAILURE);
    }
    else if (!proc)
    {
        close(pipe_[0]);
        dup2(fd, 0);
        dup2(pipe_[1], 1);
        run_cmd(args, env, paths)
    }
    else
    {
        close(pipe_[1]);
        wait(NULL);
    }
    return (pipe_[0]);
}

int main(int argv, char *argc[], char *env[])
{
    int     io[2];
    int     i;
    int     fd;
    char    **args;
    char    **paths;

    io[0] = open(argc[1], O_RDONLY);
    io[1] = open(argc[argv - 1], O_CREAT | O_WRONLY, S_IRWXU)
    if (io[0] < 0 || io[1] < 0)
    {
        perror("Could Not Open File: ");
        return (1);
    }
    paths = get_paths(char **env);
    i = 0;
    while (i < argc - 4)
    {
        args = ft_split(argv[i + 2]);
        if (!i++)
            fd = pipex(io[0], args, env);
        else
            fd = pipex(fd, args, env);
    }
}
*/
