/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:19:06 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/14 14:44:17 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int c)
{
	if (c == 32 || (c > 8 && c < 14) || c == 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	mount_n;

	mount_n = 0;
	sign = 1;
	if (!*str)
		return (mount_n);
	while (isspace(*str))
		str++;
	if (*str == '+' && ft_isdigit(*(str + 1)))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit((int )*str))
	{
		mount_n = (mount_n * 10) + (*str - 48);
		str++;
	}
	mount_n *= sign;
	return (mount_n);
}
