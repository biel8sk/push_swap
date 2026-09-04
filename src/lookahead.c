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
	if (pos <= len / 2)
	{
		*dir = 1;
		return (pos);
	}
	*dir = -1;
	return (len - pos);
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
