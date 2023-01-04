/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:27:58 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/04 12:50:48 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	int		io[2];
	int		exit_status;

	if (argc != 5)
	{
		write(2, "WRONG NUMBER OF ARGS\n", ft_strlen("WRONG NUMBER OF ARGS\n"));
		exit(EXIT_FAILURE);
	}
	exit_status = pipex(argc, argv, env, io);
	close(io[0]);
	close(io[1]);
	exit(exit_status);
}
