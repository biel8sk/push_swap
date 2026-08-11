/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:42:24 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/08 18:41:42 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		nb += 48;
		write(fd, &nb, 1);
	}
}
