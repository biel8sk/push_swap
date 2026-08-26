/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:08:52 by daneves           #+#    #+#             */
/*   Updated: 2026/08/26 01:09:23 by daneves          ###   ########.fr       */
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
	while (p->b && p->b->previous)
	{
		p->b = p->b->previous;
	}
	return (p->b);
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

void	print_st(t_stack *p, char stack)
{
	ft_printf("stack %c: ", stack);
	while (p)
	{
		ft_printf("%d -> ", p->content);
		p = p->next;
	}
	ft_putstr_fd("\n", 1);
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
	while (p->b)
	{
		pa(p);
		ra(p);
	}
}
