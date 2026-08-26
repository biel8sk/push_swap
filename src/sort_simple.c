/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:49:27 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/25 23:27:24 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_first_b(t_program *p)
{
	while (p->b && p->b->previous)
	{
		p->b = p->b->previous;
	}
	return (p->b);
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
	t_stack	*tmp;

	while (p->a)
	{
		if (p->b == NULL || p->a->content < p->b->content)
		{
			pb(p);
			continue ;
		}
		while (p->b && p->b->content < p->a->content)
		{
			pa(p);
			sa(p);
		}
	}
	tmp = p->b;
	p->b = p->a;
	p->a = tmp;
}
