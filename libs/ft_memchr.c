/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:10:17 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/04 20:42:09 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	c_c;
	char	*p;

	i = 0;
	c_c = (char) c;
	p = (char *) s;
	while (i < n)
	{
		if (p[i] == c_c)
			return ((void *)&p[i]);
		i++;
	}
	return (0);
}
