/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:58:05 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/05 20:27:38 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	mem = (unsigned char *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size * nmemb);
	return ((void *)mem);
}
