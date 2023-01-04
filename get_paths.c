/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:57:38 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/04 11:41:01 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env)
{
	int	i;

	i = 0;
	if (!env || !*env)
		return (NULL);
	while (ft_strncmp("PATH", env[i], 4))
		i++;
	return (ft_split(env[i] + 5, ':'));
}
