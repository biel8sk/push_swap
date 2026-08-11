/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 20:06:23 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/17 21:11:06 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char v, const char *set)
{
	while (*set)
	{
		if (v == *set)
			return (v == *set);
		set++;
	}
	return (v == *set);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str_trimmed;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (contains(s[i], set))
		i++;
	while (contains(s[len -1], set))
		len--;
	str_trimmed = ft_substr(s, i, len - i);
	return (str_trimmed);
}
