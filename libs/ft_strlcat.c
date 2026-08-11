/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:42:44 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/08 18:30:01 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (dst_size == 0)
		return (len_src);
	if (len_dest >= dst_size)
		return (dst_size + len_src);
	while (src[i] && i < dst_size - len_dest -1)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	dest[i + len_dest] = '\0';
	return (len_dest + ft_strlen(src));
}
