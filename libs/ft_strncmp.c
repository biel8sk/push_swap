/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:59:16 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/14 13:23:42 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	j = 0;
	p1 = (unsigned char *) str1;
	p2 = (unsigned char *) str2;
	if (n == 0)
		return (0);
	while ((p1[j] || p2[i]) && i < n && j < n)
	{
		if (p1[j] != p2[i])
			return (p1[j] - p2[i]);
		if (p1[j])
			j++;
		if (p2[i])
			i++;
	}
	return (p1[j -1] - p2[i -1]);
}
