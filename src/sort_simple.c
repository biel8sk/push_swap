/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:49:27 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/21 22:06:21 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_program *p)
{
	while (p->a)
	{
		if (p->b == NULL || p->b->content < (p->a)->content)
		{
			pb(p);
			if (!p->a)
				break ;
			continue ;
		}
		while (p->b && p->b->content < p->a->content)
		{
			p->b = p->b->next;
		}
		p->b->previous->next = p->a;
		p->b->previous = p->a;
		pa(p);
		sa(p);
	}
	while (p->b)
		pa(p);
}
