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

void	assign_index_chunk(t_stack *a, int chunk_size)
{
	t_stack	*i;
	t_stack	*j;
	int		idx;

	i = a;
	while (i)
	{
		idx = 0;
		j = a;
		while (j)
		{
			if (j->content < i->content)
				idx++;
			j = j->next;
		}
		i->idx = idx;
		i->chunk = idx / chunk_size;
		i = i->next;
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

	n = (int)p->len;
	if (n <= 1)
		return ;
	p->num_chunks = ft_sqrt(n);
	p->chunk_size = (n + p->num_chunks - 1) / p->num_chunks; //para arrendodar pra cima, [n]85 + ( [num_chucks]9 - 1) = 93 / 9 = 10. Se fosse 85 daria 9 e sobraria 4 ns
	assign_index_chunk(p->a, p->chunk_size);
}

t_stack	*find_min_in_chunk(t_stack *stk, int chunk_num)
{
	t_stack	*min_stk;

	min_stk = NULL;
	while (stk)
	{
		if (stk->chunk == chunk_num)
			if (!min_stk || stk->content < min_stk->content)
				min_stk = stk;
		stk = stk->next;
	}
	return (min_stk);
}

void	sort_medium(t_program *p)
{
	int		c;
	t_stack *min_stk;

	c = 0;
	preprocess(p);
	while (c < p->num_chunks)
	{
		min_stk = find_min_in_chunk(p->a, c);
		while (min_stk)
		{
			while (p->a->content != min_stk->content)
				ra(p);
			pb(p);
		}
		c++;
	}
	while (p->b)
	{
		pa(p);
	}
}
