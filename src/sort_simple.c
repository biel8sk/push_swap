/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:49:27 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/19 22:08:58 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_in_sorted_order(t_stack *node, t_stack **stack);

void	sort_simple(t_stack **st)
{
	t_stack	*temp_node;

	if (!*st)
		return ;
	temp_node = pop_first(st);
	sort_simple(st);
	insert_in_sorted_order(temp_node, st);
}

void	insert_in_sorted_order(t_stack *node, t_stack **stack)
{
	t_stack	*smaller;

	if (*stack == NULL || node->content < (*stack)->content)
	{
		ft_push_node(stack, node);
		return ;
	}
	smaller = pop_first(stack);
	insert_in_sorted_order(node, stack);
	ft_push_node(stack, smaller);
}
