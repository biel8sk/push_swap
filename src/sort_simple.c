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

// void	rotate(t_stack *stack)
// {
// 	if (!stack|| !stack->content)
// 		return ;
// 	rotate(&stack);
// 	//program->operations_count.ra++;
// 	ft_putstr_fd("rotateddd\n", 1);
// }

t_stack	*find_first_b(t_program *p)
{
	t_stack	*tmp;

	tmp = p->b;
	while (tmp && tmp->previous)
		tmp = tmp->previous;
	return (tmp);
}

t_stack	*find_first_stack(t_stack *stack)
{
	while (stack && stack->previous)
	{
		stack = stack->previous;
	}
	return (stack);
}

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


int	is_sorted(t_stack *st)
{
	if (!st)
		return (0);
	while (st->next)
	{
		if (st->next->content < st->content)
			return (st->next->content < st->content);
		st = st->next;
	}
	return (st->content < st->next->content);
}

void	sort_simple(t_program *p)
{
	int		highest;

	while (p->a)
	{
		highest = find_highest_stack(p->a);
		while (p->a->content != highest)
			ra(p);
		pb(p);
		
	}
	print_st(p->b, 'b');
	while (p->b)
	{
		pa(p);
		ra(p);
	}
	
	print_st(p->a, 'a');
}
	