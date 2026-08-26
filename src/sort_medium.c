/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 02:06:19 by daneves           #+#    #+#             */
/*   Updated: 2026/08/26 02:21:32 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	assign_rank(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->content < i->content)
				rank++;
			j = j->next;
		}
		i->idx = rank;
		i = i->next;
	}
}

void	assign_chunk(t_stack *a, int chunk_size)
{
	while (a)
	{
		a->chunk = a->idx / chunk_size;
		a = a->next;
	}
}

int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	preprocess(t_program *p)
{
	int	n;
	int	num_chunks;
	int	chunk_size;

	n = (int)p->len;
	assign_rank(p->a);
	num_chunks = ft_sqrt(n);
	chunk_size = (n + num_chunks - 1) / num_chunks; //para arrendodar pra cima, n85 + ( num_chucks9 - 1) = 93 / 9 = 10. Se fosse 85 daria 9 e ssobrairam 4 ns
	assign_chunk(p->a, chunk_size);
}

t_stack	*find_min_in_chunk(t_stack *a, int chunk_num)
{
	t_stack	*best;

	best = NULL;
	while (a)
	{
		if (a->chunk == chunk_num)
			if (!best || a->content < best->content)
				best = a;
		a = a->next;
	}
	return (best);
}
