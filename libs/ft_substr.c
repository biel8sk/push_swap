/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:08:16 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/08 19:13:53 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*sub;
	size_t	i;

	len_s = ft_strlen(s);
	if (start > len_s)
	{
		sub = malloc(1);
		*sub = '\0';
		return (sub);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
