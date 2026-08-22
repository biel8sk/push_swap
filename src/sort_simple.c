/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:49:27 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/22 00:14:48 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_first_b(t_program *p)
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
		ft_printf("\niniciando stacks:");
		print_st(p->b, 'b');
		print_st(p->a, 'a');
		ft_printf("\n");
		if (p->b == NULL || p->b->content > (p->a)->content)
		{
			pb(p);
			if (!p->a)
				break ;
			print_st(p->b, 'b');
			print_st(p->a, 'a');
			continue ;
		}
		if (p->b->next)
		{
			ft_printf("tem next b: %d a: %d\n", p->b->content, p->a->content);
			while (p->b->next && p->b->content < p->a->content)
			{
				ft_printf("b menor que a %d < %d\n", p->b->content, p->a->content);
				p->b = p->b->next;
				ft_printf("novo b %d\n", p->b->content);

			}
			if (!p->b->next && p->b->content < p->a->content)
			{
				ft_printf("não tem next em b e b é menor que a %d < %d\n", p->b->content, p->a->content);
				tmp = pop_first(&p->a);
				ft_printf("temp ultima: %d\n", tmp->content);
				tmp->previous = p->b;
				p->b->next = tmp;
				p->b = find_first_b(p);
				print_st(p->b, 'b');
				ft_printf("stack apos adicionar a ultima\n\n");
				continue ;
			}
			tmp = pop_first(&p->a);
			ft_printf("temp meio: %d\n", tmp->content);
			if (p->b->previous)
				p->b->previous->next = tmp;
			tmp->previous = p->b->previous;
			p->b->previous = tmp;
			tmp->next = p->b;
			p->b = find_first_b(p);
			print_st(p->b, 'b');
			ft_printf("stack apos adicionar no meio\n\n");
			continue ;
		}
		ft_printf("n tem proximo %d\n a: %d\n", p->b->content, p->a->content);
		tmp = pop_first(&p->a);
		tmp->previous = p->b;
		p->b->next = tmp;
	}
	tmp = p->b;
	p->b = p->a;
	p->a = tmp;
}
