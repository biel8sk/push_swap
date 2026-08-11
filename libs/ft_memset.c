/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:01:16 by gpires-c          #+#    #+#             */
/*   Updated: 2026/05/29 19:53:47 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int c, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)buffer;
	while (i < size)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
