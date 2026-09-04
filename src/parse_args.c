/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 04:21:33 by daneves           #+#    #+#             */
/*   Updated: 2026/09/04 04:21:33 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str, int *out)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str++ - '0');
		if (n > 2147483648L)
			return (0);
	}
	if (*str || (sign == 1 && n > 2147483647L))
		return (0);
	*out = (int)(n * sign);
	return (1);
}