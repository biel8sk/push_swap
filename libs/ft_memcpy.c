/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:23:09 by gpires-c          #+#    #+#             */
/*   Updated: 2026/07/18 18:56:50 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*p2;
	size_t			i;

	p = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p2[i] = p[i];
		i++;
	}
	return (p2);
}
