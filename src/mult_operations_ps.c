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

void	ss(t_program *program)
{
	t_stack	*a;
	t_stack	*b;

	a = program->a;
	b = program->b;
	if (a && a->next)
		swap_top(&a);
	if (b && b->next)
		swap_top(&b);
	program->operations_count.ss++;
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_program *program)
{
	t_stack	*a;
	t_stack	*b;

	a = program->a;
	b = program->b;
	if (a && a->next)
		rotate(&a, &program->a_tail);
	if (b && b->next)
		rotate(&b, &program->b_tail);
	program->operations_count.ss++;
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_program *program)
{
	t_stack	*a;
	t_stack	*b;

	a = program->a;
	b = program->b;
	reverse_rotate(&a);
	reverse_rotate(&b);
	program->operations_count.ss++;
	ft_putstr_fd("ss\n", 1);
}
