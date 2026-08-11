/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:27:11 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/17 21:13:47 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 2;
	if (n < 0)
	{
		len++;
	}
	while (n > 9 || n < -9)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static void	calc_operations_and_set_char(char *a, int n, int len, int is_n)
{
	int		c;
	long	nl;
	int		i;

	nl = (long) n;
	i = len -1;
	a[i--] = 0;
	if (is_n)
	{
		a[0] = '-';
		nl *= -1;
		while (i > 0)
		{
			c = nl % 10;
			nl /= 10;
			a[i--] = c + 48;
		}
		return ;
	}
	while (i >= 0)
	{
		c = nl % 10;
		nl /= 10;
		a[i--] = c + 48;
	}
}

char	*ft_itoa(int n)
{
	char	*a;
	int		len;
	int		is_negative;

	is_negative = n < 0;
	len = get_len(n);
	a = (char *)malloc(len);
	calc_operations_and_set_char(a, n, len, is_negative);
	return (a);
}

// int	main(void)
// {
// 	#include "stdio.h"

// 	printf("%s ", ft_itoa(123));
// 	printf("%s ", ft_itoa(48928));
// }
