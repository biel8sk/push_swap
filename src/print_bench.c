/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 05:29:41 by daneves           #+#    #+#             */
/*   Updated: 2026/09/04 05:29:41 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strategy_name(t_flag sel)
{
	if (sel == SIMPLE)
		return ("Simple");
	if (sel == MEDIUM)
		return ("Medium");
	if (sel == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*complexity_str(t_flag meth)
{
	if (meth == SIMPLE)
		return ("O(n^2)");
	if (meth == MEDIUM)
		return ("O(n√n)");
	return ("O(n log n)");
}

int	total_ops(t_ops_count *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb + c->ra
		+ c->rb + c->rr + c->rra + c->rrb + c->rrr);
}

void	print_disorder(double disorder)
{
	int	percent;

	percent = (int)(disorder * 10000 + 0.5);
	ft_printfd(2, "[bench] disorder:  %d.", percent / 100);
	if (percent % 100 < 10)
		ft_printfd(2, "0");
	ft_printfd(2, "%d%%\n", percent % 100);
}

void	print_bench(t_program *p)
{
	t_ops_count	*c;

	c = &p->operations_count;
	print_disorder(p->disorder);
	ft_printfd(2, "[bench] strategy:  %s / %s\n",
		strategy_name(p->selector), complexity_str(p->method));
	ft_printfd(2, "[bench] total_ops:  %d\n", total_ops(c));
	ft_printfd(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		c->sa, c->sb, c->ss, c->pa, c->pb);
	ft_printfd(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		c->ra, c->rb, c->rr, c->rra, c->rrb, c->rrr);
}