/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 07:27:15 by daneves           #+#    #+#             */
/*   Updated: 2026/09/01 07:27:15 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_program *p)
{
	int		max_bits;
	int		bit;
	size_t	i;

	if (p->len <= 1)
		return ;
	max_bits = 0;
	while ((p->len - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < p->len)
		{
			if (((p->a->rank >> bit) & 1) == 0)
				pb(p);
			else
				ra(p);
			i++;
		}
		while (p->b)
			pa(p);
		bit++;
	}
}
