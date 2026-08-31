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
	int		count;

	i = a;
	while (i)
	{
		count = 0;
		j = a;
		while (j)
		{
			if (j->content < i->content)
				count++;
			j = j->next;
		}
		i->rank = count;
		i->chunk = count / chunk_size;
		i = i->next;
	}
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

int	has_chunk(t_stack *stk, int c)
{
	while (stk)
	{
		if (stk->chunk == c)
			return (1);
		stk = stk->next;
	}
	return (0);
}

// t_stack	*find_min_in_chunk(t_stack *a, int chunk_num)
// {
// 	t_stack	*min_stk;

// 	min_stk = NULL;
// 	while (a)
// 	{
// 		if (a->chunk == chunk_num)
// 			if (!min_stk || a->rank < min_stk->rank)
// 				min_stk = a;
// 		a = a->next;
// 	}
// 	return (min_stk);
// }

void	sort_medium(t_program *p)
{
	int		c;

	c = 0;
	preprocess(p);
	while (c < p->num_chunks - 1)
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
	
	print_st(p->a, 'a');
	print_st(p->b, 'b');
	while (p->b)
	{
		pa(p);
		//ra(p);
	}
}

//Veeer::::
// Será que pra complex conseguimos deixar metade dos chunks em a e ir trabalhando ao mesmo tempo?