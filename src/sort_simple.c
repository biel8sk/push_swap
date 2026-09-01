/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:08:52 by daneves           #+#    #+#             */
/*   Updated: 2026/08/26 01:48:06 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	find_highest_stack(t_stack *stack)
{
	int	highest;

	if (stack)
		highest = stack->content;
	while (stack)
	{
		if (stack->content >= highest)
			highest = stack->content;
		stack = stack->next;
	}
	return (highest);
}


void	sort_simple(t_program *p)
{
	int		highest;

	if (p->len <= 1)
		return ;
	while (p->a)
	{
		highest = find_highest_stack(p->a);
		while (p->a->content != highest)
			ra(p);
		pb(p);
	}
	while (p->b)
	{
		pa(p);
		ra(p);
	}
}
