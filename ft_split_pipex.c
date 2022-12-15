/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:52:03 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/12/13 17:42:18 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	ft_free_all_mfs(char **p)
// {
// 	while (*p)
// 		free(p++);
// 	free(p);
// }

// static int	ft_count_words(char *str, char c)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	if (!str)
// 		return (0);
// 	while (*str)
// 	{
// 		i = 0;
// 		while (str[i] && str[i] != c)
// 			i++;
// 		if (i)
// 		{
// 			count++;
// 			str += i;
// 		}
// 		else
// 		str++;
// 	}
// 	return (count);
// }

static void	ft_cpychars(char *str, char **p, char c)
{
	int		len;
	int		i;
	char	**ptr;

	i = 0;
	ptr = p;
	while (str[i])
	{
		len = 0;
		while (str[i + len] && str[i + len] != c)
			len++;
		if (len)
		{
			*p++ = ft_substr(str, i, len);
			*p++ = ft_substr(str + len + 1, 0, ft_strlen(str + len));
			i += ft_strlen(str);
		}
		else
		i++;
	}
	*p = NULL;
}

char	**ft_split_pipe(char const *s, char c)
{
	char	**p;
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	p = malloc(3 * sizeof(char *));
	if (p == NULL)
		return (NULL);
	ft_cpychars(str, p, c);
	return (p);
}

// #include <stdio.h>

// int main()
// {
// 	char **s = ft_split("grep hello", ' ', 3);
// 	printf("|%s|\n", s[0]);
// 	printf("|%s|\n", s[1]);
// 	printf("|%s|\n", s[2]);
// 	printf("|%s|\n", s[3]);
// }