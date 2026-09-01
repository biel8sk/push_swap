/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:56:05 by daneves           #+#    #+#             */
/*   Updated: 2026/08/30 20:56:05 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_cost(int pos, int len, int *dir)
{
	if (pos <= len  /2)
	{
		*dir = 1;
		return (pos);
	}
	*dir = -1;
	return (len - pos);
}

int	set_pos(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		stk->pos = i++;
		stk = stk->next;
	}
	return (i);
}

int	pos_of_min(t_stack *stk)
{
	int	min;
	int	pos;

	if (!stk)
		return(0);
	min = stk->rank;
	pos = stk->pos;
	while (stk)
	{
		if (stk->rank < min)
		{
			min = stk->rank;
			pos = stk->pos;
		}
		stk = stk->next;
	}
	return (pos);
}


int	find_insert_pos(t_stack *stk, int curr_rank, int len_stk)
{
	t_stack	*node;
	int		next_rank;
	int		target_pos;

	node = stk;
	next_rank = len_stk;
	target_pos = pos_of_min(stk);
	while (node)
	{
		if (node->rank > curr_rank && node->rank < next_rank)
		{
			target_pos = node->pos;
			next_rank = node->rank;
		}
		node = node->next;
	}
	return (target_pos);
}

void	move_cost_ba(t_program *p, t_stack *node_b, t_move *m)
{
	int	target_pos_a;

	m->rot_b = rotate_cost(node_b->pos, p->len_b, &m->dir_b);
	target_pos_a = find_insert_pos(p->a, node_b->rank, p->len);
	m->rot_a = rotate_cost(target_pos_a, p->len_a, &m->dir_a);
	if (m->dir_a == m->dir_b)
		m->cost = ft_max(m->rot_a, m->rot_b);
	else
		m->cost = m->rot_a + m->rot_b;
	m->node = node_b;
}

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
		move_cost_ba(p, node, &curr);     // ← calcula o preço deste
		if (best.cost == -1 || curr.cost < best.cost)
			best = curr;                   // ← guarda se for melhor
		node = node->next;
	}
	return (best);
}


void	execute_move_ba(t_program *p, t_move *m)
{
	// ft_printfd(2, "exec: rank=%d rot_a=%d dir_a=%d rot_b=%d dir_b=%d target=?\n",
	// m->node->rank, m->rot_a, m->dir_a, m->rot_b, m->dir_b);
	while (m->rot_a > 0 && m->rot_b > 0 && m->dir_a == m->dir_b)
	{
		if (m->dir_a == 1)
			rr(p);
		else
			rrr(p);
		m->rot_a--;
		m->rot_b--;
	}
	while (m->rot_a > 0)
	{
		if (m->dir_a == 1)
			ra(p);
		else
			rra(p);
		m->rot_a--;
	}
	while (m->rot_b > 0)
	{
		if (m->dir_b == 1)
			rb(p);
		else
			rrb(p);
		m->rot_b--;
	}
	pa(p);
}

