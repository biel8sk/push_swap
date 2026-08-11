/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:25:00 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/04 22:53:16 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (n == 0)
		return (src_len);
	if (n > src_len + 1)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < n -1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (src_len);
}
