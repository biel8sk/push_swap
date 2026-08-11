/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:47:26 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/01 20:15:36 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	total;
	size_t	i;
	char	*ptr;

	total = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((total + 1));
	if (!new_str)
		return (NULL);
	ptr = (char *)s1;
	i = 0;
	while (ptr[i])
	{
		new_str[i] = ptr[i];
		i++;
	}
	ptr = (char *)s2;
	while (*ptr)
		new_str[i++] = *ptr++;
	new_str[total] = 0;
	return (new_str);
}
