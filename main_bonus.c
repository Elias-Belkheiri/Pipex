/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:20:29 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 16:09:49 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	int		io[2];

	if (argc < 6)
	{
		write(2, "NOT ENOUGH ARGS\n", ft_strlen("NOT ENOUGH ARGS\n"));
		exit(EXIT_FAILURE);
	}
	pipex(argc, argv, env, io);
	close(io[0]);
	close(io[1]);
	unlink("/tmp/tmpfile");
}
