/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:47:26 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/12 17:33:28 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puthex_fd(unsigned long number, char flag, int fd)
{
	char			*lower;
	char			*upper;
	char			*output;
	size_t			len_hex;
	size_t			i;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	len_hex = ft_nlen_hex(number);
	output = ft_calloc(len_hex, sizeof(char));
	i = len_hex;
	while (number > 0)
	{
		if (flag == 'X')
			output[i -1] = upper[number & 15];
		else if (flag == 'x')
			output[i -1] = lower[number & 15];
		number >>= 4;
		i--;
	}
	write(fd, output, len_hex);
	free(output);
	return (len_hex);
}
