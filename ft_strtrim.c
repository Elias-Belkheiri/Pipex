/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:19 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/12/27 15:28:19 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check(char *trim, char a)
{
	while (*trim)
	{
		if (*trim == a)
			return (1);
		trim++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;
	char	*tr;
	int		j;

	str = (char *)s1;
	tr = (char *)set;
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (ft_check(tr, str[i]))
		i++;
	len = ft_strlen(str) - 1;
	while (ft_check(tr, str[len]))
	{
		len--;
		j++;
	}
	return (ft_substr(str, i, ft_strlen(str) - j - i));
}
