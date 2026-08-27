/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:15:05 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/12 17:33:08 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revert_str(char *str)
{
	size_t	len;
	size_t	i;
	char	temp;

	if (!str)
		return (str);
	len = ft_strlen(str);
	i = 0;
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len -1 - i];
		str[len -1 - i] = temp;
		i++;
	}
	return (str);
}
