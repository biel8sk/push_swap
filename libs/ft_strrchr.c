/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:52:21 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/04 21:29:59 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	str_len;
	int	i;

	i = 0;
	str_len = ft_strlen(str);
	if (c == 0)
		return ((char *)&str[str_len]);
	while (str_len >= i)
	{
		if (str[str_len] == (char) c)
			return ((char *)&str[str_len]);
		str_len--;
	}
	return (0);
}
