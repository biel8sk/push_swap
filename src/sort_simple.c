/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:49:27 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/22 07:22:08 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rotate(t_stack *stack)
// {
// 	if (!stack|| !stack->content)
// 		return ;
// 	rotate(&stack);
// 	//program->operations_count.ra++;
// 	ft_putstr_fd("rotateddd\n", 1);
// }

t_stack	*find_first_b(t_program *p)
{
	while (p->b && p->b->previous)
	{
		p->b = p->b->previous;
	}
	return (p->b);
}

t_stack	*find_first_stack(t_stack *stack)
{
	while (stack && stack->previous)
	{
		stack = stack->previous;
	}
	return (stack);
}

int	find_highest_stack(t_stack *stack)
{
	int	highest;

	highest = 0;
	while (stack)
	{
		if (stack->content >= highest)
			highest = stack->content;
		stack = stack->next;
	}
	return (highest);
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
	int		highest;

	while (p->a)
	{
		//p->b = find_first_b(p);
		highest = find_highest_stack(p->a);
		//ft_printf("\nHIGHEST: %d", highest);
		// if (p->b == NULL || p->b->content > (p->a)->content)
		// {
		// 	pb(p);
		// 	p->b->idx = idx++;
		// 	ft_printf("\nidx: %d", p->b->idx);
		// 	if (!p->a)
		// 		break ;
		// 	continue ;
		// }
		// if (p->b->next)
		// {
		// 	while (p->b->next && p->b->content < p->a->content)
		// 	{
		// 		p->b->idx = idx++;
		// 		ft_printf("\nidx: %d", p->b->idx);
		// 		p->b = p->b->next;
		// 	}
		// 	if (!p->b->next && p->b->content < p->a->content)
		// 	{
		// 		tmp = pop_first(&p->a);
		// 		tmp->previous = p->b;
		// 		p->b->next = tmp;
		// 		p->b = find_first_b(p);
		// 		continue ;
		// 	}
		// 	tmp = pop_first(&p->a);
		// 	if (p->b->previous)
		// 		p->b->previous->next = tmp;
		// 	tmp->previous = p->b->previous;
		// 	p->b->previous = tmp;
		// 	tmp->next = p->b;
		// 	p->b = find_first_b(p);
		// 	continue ;
		// }
		while (p->a->content != highest)
		{
			//ft_printf("\nN MAIOR: %d", p->a->content);
			ra(p);
			// if (p->a->next)
			// 	ra()
			// else
			// 	p->a = find_first_stack(p->a);
		}
		//ft_printf("\nPA - HIGHEST: %d", p->a->content);
		//tmp = find_first_stack(p->a);
		//ft_printf("\ntmp: %d", tmp->content);
		pb(p);
		//p->a = tmp;
		//print_st(p->a, 'a');
		//print_st(p->b, 'b');
		// if (!p->a)
		// 	ft_printf("\nvoltou?, a: %d", 99);
		// ft_printf("\nvoltou?, be: %d", p->b->content);
		// tmp = pop_first(&p->a);
		// tmp->previous = p->b;
		// p->b->next = tmp;
	}
	tmp = p->b;
	p->b = p->a;
	p->a = tmp;
}


