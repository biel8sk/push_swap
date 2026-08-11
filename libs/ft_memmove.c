/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:40:20 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/04 20:35:28 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	size_t			i;

	p_dst = (unsigned char *) dest;
	p_src = (unsigned char *) src;
	i = 0;
	if (!*p_src && !*p_dst)
		return (NULL);
	while (i < n)
	{
		if (p_src < p_dst)
		{
			p_dst[n -1] = p_src[n -1];
			n--;
			continue ;
		}
		p_dst[i] = p_src[i];
		i++;
	}
	return (p_dst);
}
