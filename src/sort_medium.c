/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 02:06:19 by daneves           #+#    #+#             */
/*   Updated: 2026/08/26 03:31:28 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(t_program *p)
{
	pa(p);
	pa(p);
	if (p->a->rank > p->a->next->rank)
		sa(p);
}

void	align_a(t_program *p)
{
	int	cost;
	int	dir;

	p->len_a = set_pos(p->a);
	cost = rotate_cost(pos_of_min(p->a), p->len_a, &dir);
	while (cost-- > 0)
	{
		if (dir == 1)
			ra(p);
		else
			rra(p);
	}
}

void	sort_medium(t_program *p)
{
	int		c;
	t_move	m;

	if (p->len <= 1)
		return ;
	c = 0;
	preprocess_medium(p);
	while (c < p->num_chunks)
	{
		while (has_chunk(p->a, c))
		{
			if (p->a->chunk <= c)
				pb(p);
			else
				ra(p);
		}
		c++;
	}
	init_a(p);
	while (p->b)
	{
		m = best_move_ba(p);
		execute_move_ba(p, &m);
	}
	align_a(p);
}
