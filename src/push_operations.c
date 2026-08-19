/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:31:58 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/19 19:37:29 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_program *program)
{
	t_stack	*node;

	node = pop_first(&program->b);
	ft_push_node(&program->a, node);
	ft_putstr_fd("pa\n", 1);
	program->operations_count.pa++;
}

void	pb(t_program *program)
{
	t_stack	*node;

	node = pop_first(&program->a);
	ft_push_node(&program->b, node);
	ft_putstr_fd("pb\n", 1);
	program->operations_count.pb++;
}
