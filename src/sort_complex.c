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

// int	has_chunk(t_stack *stk, int c)
// {
// 	while (stk)
// 	{
// 		if (stk->chunk == c)
// 			return (1);
// 		stk = stk->next;
// 	}
// 	return (0);
// }

// void	init_a(t_program *p)
// {
// 	pa(p);
// 	pa(p);
// 	if (p->a->rank > p->a->next->rank)
// 		sa(p);
// }

// void	align_a(t_program *p)
// {
// 	int	cost;
// 	int	dir;

// 	p->len_a = set_pos(p->a);
// 	cost = rotate_cost(pos_of_min(p->a), p->len_a, &dir);
// 	while (cost-- > 0)
// 	{
// 		if (dir == 1)
// 			ra(p);
// 		else
// 			rra(p);
// 	}
// }

void	sort_complex(t_program *p)
{
	//int		c;
	//t_move	m;
	int	max_bits;
	int	bit;
	size_t	i;

	if (p->len <= 1)
		return ;
	//c = 0;
	preprocess(p);
	max_bits = 0;
	// while (c < p->num_chunks)
	// {
	// 	while (has_chunk(p->a, c))
	// 	{
	// 		if (p->a->chunk <= c)
	// 			pb(p);
	// 		else
	// 			ra(p);
	// 	}
	// 	c++;
	// }
	// init_a(p);
	// while (p->b)
	// {
	// 	m = best_move_ba(p);
	// 	execute_move_ba(p, &m);
	// }
	// while (p->b)
	// {
	// 	m = best_move_ba(p);
	// 	execute_move_ba(p, &m);
	// }
	// align_a(p);
	while ((p->len - 1) >> max_bits)
		max_bits++;
	bit = 0;
	ft_printfd(2, "\nIncio A\n:");
	print_st(p->a, 'a');
	ft_printfd(2, "\nIncio B\n:");
	print_st(p->b, 'b');
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
		
		ft_printfd(2, "\nA\n:");
		print_st(p->a, 'a');
		ft_printfd(2, "\nB\n:");
		print_st(p->b, 'b');
		while (p->b)
			pa(p);
		ft_printfd(2, "\nIncio A:");
		print_st(p->a, 'a');
		ft_printfd(2, "\nIncio B:");
		print_st(p->b, 'b');
		bit++;
	}
}