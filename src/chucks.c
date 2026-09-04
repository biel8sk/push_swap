/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chucks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 06:23:36 by daneves           #+#    #+#             */
/*   Updated: 2026/09/04 06:23:36 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_chunks(t_stack *stk, int chunk_size)
{
	while (stk)
	{
		stk->chunk = stk->rank / chunk_size;
		stk = stk->next;
	}
}

void	preprocess_medium(t_program *p)
{
	int	n;

	n = (int)p->len;
	if (n <= 1)
		return ;
	p->num_chunks = ft_sqrt(n) / 3;
	if (p->num_chunks < 1)
		p->num_chunks = 1;
	p->chunk_size = (n + p->num_chunks - 1) / p->num_chunks;
	assign_chunks(p->a, p->chunk_size);
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
