/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:37:47 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/16 03:49:17 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_program *p)
{
	t_stack	*st;

	st = p->a;
	if (!st || !st->next)
		return ;
	swap_top(&st);
	p->operations_count.sa++;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_program *p)
{
	t_stack	*st;

	st = p->b;
	if (!st || !st->next)
		return ;
	swap_top(&st);
	p->operations_count.sb++;
	ft_putstr_fd("sb\n", 1);
}


