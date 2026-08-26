/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:33:44 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/22 02:51:20 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_program *program)
{
	if (!program || !program->a)
		return ;
	rotate(&program->a);
	program->operations_count.ra++;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_program *program)
{
	if (!program || !program->b)
		return ;
	rotate(&program->b);
	program->operations_count.rb++;
	ft_putstr_fd("rb\n", 1);
}

void	rra(t_program *program)
{
	if (!program || !program->a)
		return ;
	reverse_rotate(&program->a);
	program->operations_count.rra++;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_program *program)
{
	if (!program || !program->b)
		return ;
	reverse_rotate(&program->b);
	program->operations_count.rrb++;
	ft_putstr_fd("rrb\n", 1);
}
