/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:05:32 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/12 17:33:25 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putprt_fd(void *p, int fd)
{
	unsigned long	memory;
	const char		*base;
	size_t			i;
	char			buffer[19];

	memory = (unsigned long)p;
	if (!memory)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	base = "0123456789abcdef";
	i = 0;
	buffer[i] = 0;
	while (memory > 0 && i < 16)
	{
		buffer[i++] = base[memory & 15];
		memory >>= 4;
	}
	buffer[i] = 0;
	ft_strlcat(buffer, "x0", 19);
	ft_revert_str(buffer);
	write(fd, buffer, i + 2);
	return (i + 2);
}
