/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_operations_ps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:36:36 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/19 19:31:14 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_program *p)
{
	swap_top(&p->a);
	swap_top(&p->b);
	p->operations_count.ss++;
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_program *p)
{
	rotate(&p->a);
	rotate(&p->b);
	p->operations_count.rr++;
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_program *p)
{
	reverse_rotate(&p->a);
	reverse_rotate(&p->b);
	p->operations_count.rrr++;
	ft_putstr_fd("rrr\n", 1);
}
