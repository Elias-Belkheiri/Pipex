/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:16:46 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/12/15 11:29:10 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0 || !str2)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}	
	if (i >= n)
		i--;
	if (str1[i] > str2[i])
		return (1);
	else if (str1[i] < str2[i])
		return (-1);
	return (0);
}
