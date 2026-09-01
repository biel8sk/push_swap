/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 05:13:09 by daneves           #+#    #+#             */
/*   Updated: 2026/09/01 05:13:09 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_str_fd(int fd, va_list args, size_t *char_count)
{
	char	*p;

	p = va_arg(args, char *);
	if (!p)
	{
		ft_putstr_fd("(null)", fd);
		(*char_count) += 6;
		return ;
	}
	(*char_count) += ft_strlen(p);
	ft_putstr_fd(p, fd);
}

void	handle_number_fd(int fd, char *arg, va_list args, size_t *char_count)
{
	unsigned int	number;
	int				s_number;

	if (*(arg + 1) == 'd' || *(arg + 1) == 'i')
	{
		s_number = va_arg(args, int);
		ft_putnbr_fd(s_number, fd);
		(*char_count) += ft_numlen(s_number);
	}
	else if (*(arg + 1) == 'u')
	{
		number = va_arg(args, unsigned int);
		ft_putunbr_fd(number, fd);
		(*char_count) += ft_unumlen(number);
	}	
}

void	handle_hex_number_fd(int fd, char *arg, va_list args, size_t *char_count)
{
	unsigned long	number;

	number = (unsigned long) va_arg(args, unsigned int);
	if (number == 0)
	{
		write(fd, "0", 1);
		(*char_count)++;
		return ;
	}
	(*char_count) += ft_puthex_fd(number, *arg, fd);
}

void	handle_arg_fd(int fd, char *arg, va_list args, size_t *char_count)
{
	if (*(arg + 1) == 'c')
	{
		ft_putchar_fd(va_arg(args, int), fd);
		(*char_count)++;
	}
	else if (*(arg + 1) == 's')
		handle_str_fd(fd, args, char_count);
	else if (*(arg + 1) == 'p')
		(*char_count) += ft_putprt_fd(va_arg(args, void *), fd);
	else if (*(arg + 1) == 'd' || *(arg + 1) == 'i' || *(arg + 1) == 'u')
		handle_number_fd(fd, arg, args, char_count);
	else if (*(arg + 1) == 'x' || *(arg + 1) == 'X')
		handle_hex_number_fd(fd, (arg + 1), args, char_count);
	else if (*(arg + 1) == '%')
	{
		ft_putchar_fd('%', fd);
		(*char_count)++;
	}
}

int	ft_printfd(int fd, char const *input, ...)
{
	va_list	args;
	char	*arg;
	size_t	i;
	size_t	char_count;
	//char	*known_args;

	//known_args = "cspdiuxX%";
	va_start(args, input);
	i = 0;
	char_count = 0;
	while (input[i] != 0)
	{
		while (input[i] != '%' && input[i])
		{
			ft_putchar_fd(input[i++], fd);
			char_count++;
		}
		if (input[i])
		{
			arg = (char *) &input[i];
			handle_arg_fd(fd, arg, args, &char_count);
			i += 2;
		}
	}
	return (va_end(args), char_count);
}