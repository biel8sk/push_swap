/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:53:37 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/05 19:09:09 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	i = 0;
	j = 0;
	len_little = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		while (haystack[j + i] == needle[j] && haystack[j + i]
			&& needle[j] && i + j < n)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
