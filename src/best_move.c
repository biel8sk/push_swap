/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 06:06:58 by daneves           #+#    #+#             */
/*   Updated: 2026/09/04 06:06:58 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	best_move_ba(t_program *p)
{
	t_move	best;
	t_move	curr;
	t_stack	*node;

	p->len_a = set_pos(p->a);
	p->len_b = set_pos(p->b);
	best.cost = -1;
	node = p->b;
	while (node)
	{
		move_cost_ba(p, node, &curr);
		if (best.cost == -1 || curr.cost < best.cost)
			best = curr;
		node = node->next;
	}
	return (best);
}

void	rotate_a_n(t_program *p, int n, int dir)
{
	while (n-- > 0)
	{
		if (dir == 1)
			ra(p);
		else
			rra(p);
	}
}

void	rotate_b_n(t_program *p, int n, int dir)
{
	while (n-- > 0)
	{
		if (dir == 1)
			rb(p);
		else
			rrb(p);
	}
}

void	execute_move_ba(t_program *p, t_move *m)
{
	while (m->rot_a > 0 && m->rot_b > 0 && m->dir_a == m->dir_b)
	{
		if (m->dir_a == 1)
			rr(p);
		else
			rrr(p);
		m->rot_a--;
		m->rot_b--;
	}
	rotate_a_n(p, m->rot_a, m->dir_a);
	rotate_b_n(p, m->rot_b, m->dir_b);
	pa(p);
}
