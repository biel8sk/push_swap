/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:52:48 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/20 20:05:06 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	j = 0;
	i = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j] == 0)
			break ;
		i = j;
		while (s[i] != c && s[i])
			i++;
		j = i;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str_splited;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str_splited = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!str_splited)
		return (NULL);
	while (s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j] == 0)
			break ;
		i = j;
		while (s[i] != c && s[i])
			i++;
		str_splited[k++] = ft_substr(s, j, i - j);
		j = i;
	}
	return (str_splited[k] = 0, str_splited);
}
