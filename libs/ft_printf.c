/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 22:11:33 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/12 17:33:36 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_str(va_list args, size_t *char_count)
{
	char	*p;

	p = va_arg(args, char *);
	if (!p)
	{
		ft_putstr_fd("(null)", 1);
		(*char_count) += 6;
		return ;
	}
	(*char_count) += ft_strlen(p);
	ft_putstr_fd(p, 1);
}

void	handle_number(char *arg, va_list args, size_t *char_count)
{
	unsigned int	number;
	int				s_number;

	if (*(arg + 1) == 'd' || *(arg + 1) == 'i')
	{
		s_number = va_arg(args, int);
		ft_putnbr_fd(s_number, 1);
		(*char_count) += ft_numlen(s_number);
	}
	else if (*(arg + 1) == 'u')
	{
		number = va_arg(args, unsigned int);
		ft_putunbr_fd(number, 1);
		(*char_count) += ft_unumlen(number);
	}	
}

void	handle_hex_number(char *arg, va_list args, size_t *char_count)
{
	unsigned long	number;

	number = (unsigned long) va_arg(args, unsigned int);
	if (number == 0)
	{
		write(1, "0", 1);
		(*char_count)++;
		return ;
	}
	(*char_count) += ft_puthex_fd(number, *arg, 1);
}

void	handle_arg(char *arg, va_list args, size_t *char_count)
{
	if (*(arg + 1) == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*char_count)++;
	}
	else if (*(arg + 1) == 's')
		handle_str(args, char_count);
	else if (*(arg + 1) == 'p')
		(*char_count) += ft_putprt_fd(va_arg(args, void *), 1);
	else if (*(arg + 1) == 'd' || *(arg + 1) == 'i' || *(arg + 1) == 'u')
		handle_number(arg, args, char_count);
	else if (*(arg + 1) == 'x' || *(arg + 1) == 'X')
		handle_hex_number((arg + 1), args, char_count);
	else if (*(arg + 1) == '%')
	{
		ft_putchar_fd('%', 1);
		(*char_count)++;
	}
}

int	ft_printf(char const *input, ...)
{
	va_list	args;
	char	*arg;
	size_t	i;
	size_t	char_count;
	char	*known_args;

	known_args = "cspdiuxX%";
	va_start(args, input);
	i = 0;
	char_count = 0;
	while (input[i] != 0)
	{
		while (input[i] != '%' && input[i])
		{
			ft_putchar_fd(input[i++], 1);
			char_count++;
		}
		if (input[i])
		{
			arg = (char *) &input[i];
			handle_arg(arg, args, &char_count);
			i += 2;
		}
	}
	return (va_end(args), char_count);
}
