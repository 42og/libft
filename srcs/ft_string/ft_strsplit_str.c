/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:59:38 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 14:35:14 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static char		*ft_copy(char const *s, char const *str)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] && !ft_strchr(str, s[i]))
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && !ft_strchr(str, s[i]))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	nb_words(char const *s, char const *str)
{
	size_t	cpt;
	size_t	i;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && !ft_strchr(str, s[i]))
			|| (!ft_strchr(str, s[i]) && ft_strchr(str, s[i - 1])))
			cpt++;
		i++;
	}
	return (cpt);
}

char			**ft_strsplit_str(char const *s, char const *str)
{
	char	**res;
	size_t	word;
	size_t	i;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (nb_words(s, str) + 1));
	if (!res)
		return (NULL);
	word = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && !ft_strchr(str, s[i]))
			|| (!ft_strchr(str, s[i]) && ft_strchr(str, s[i - 1])))
		{
			res[word++] = ft_copy(s + i, str);
		}
		i++;
	}
	res[word] = NULL;
	return (res);
}
