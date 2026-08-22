/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:49:27 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/22 00:28:16 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_first_b(t_program *p)
{
	while (p->b && p->b->previous)
	{
		p->b = p->b->previous;
	}
	return (p->b);
}

void	print_st(t_stack *p, char stack)
{
	ft_printf("stack %c: ", stack);
	while (p)
	{
		ft_printf("%d -> ", p->content);
		p = p->next;
	}
	ft_putstr_fd("\n", 1);
}

void	sort_simple(t_program *p)
{
	t_stack	*tmp;

	while (p->a)
	{
		p->b = find_first_b(p);
		if (p->b == NULL || p->b->content > (p->a)->content)
		{
			pb(p);
			if (!p->a)
				break ;
			continue ;
		}
		if (p->b->next)
		{
			while (p->b->next && p->b->content < p->a->content)
			{
				p->b = p->b->next;
			}
			if (!p->b->next && p->b->content < p->a->content)
			{
				tmp = pop_first(&p->a);
				tmp->previous = p->b;
				p->b->next = tmp;
				p->b = find_first_b(p);
				continue ;
			}
			tmp = pop_first(&p->a);
			if (p->b->previous)
				p->b->previous->next = tmp;
			tmp->previous = p->b->previous;
			p->b->previous = tmp;
			tmp->next = p->b;
			p->b = find_first_b(p);
			continue ;
		}
		tmp = pop_first(&p->a);
		tmp->previous = p->b;
		p->b->next = tmp;
	}
	tmp = p->b;
	p->b = p->a;
	p->a = tmp;
}
