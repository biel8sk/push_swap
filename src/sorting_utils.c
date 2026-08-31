/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 19:03:04 by daneves           #+#    #+#             */
/*   Updated: 2026/08/30 19:03:04 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int	find_highest_rank(t_stack *stk)
{
	int	highest;

	if (stk)
		highest = stk->rank;
	while (stk)
	{
		if (stk->rank > highest)
			highest = stk->rank;
		stk = stk->next;
	}
	return (highest);
}


int	find_smallest_rank(t_stack *stk)
{
	int	smallest;

	if (stk)
		smallest = stk->rank;
	while (stk)
	{
		if (stk->rank < smallest)
			smallest = stk->rank;
		stk = stk->next;
	}
	return (smallest);
}

int	stk_is_sorted(t_stack *stk)
{
	while (stk && stk->next)
	{
		if (stk->rank > stk->next->rank)
			return (0);
		stk = stk->next;
	}
	return (1);
}
void	rotate_stk(t_program *p, char n)
{
	if (n == 'a')
		ra(p);
	else
		rb(p);
}

void	swap_stk(t_program *p, char n)
{
	if (n == 'a')
		sa(p);
	else
		sb(p);
}

void	print_rank(t_stack *stk)
{
	while (stk)
	{
		ft_printf("%d ", stk->rank);
		stk = stk->next;
	}
	ft_printf("\n");
}

void	sort_simple_stk(t_program *p, char stk_name)
{
	t_stack	**stk;
	int		count;

	if (stk_name == 'a')
		stk = &p->a;
	if (stk_name == 'b')
		stk = &p->b;
	count = 0;
		ft_printf("IS SORTED: %d\n", stk_is_sorted(*stk));
	ft_printf("IS SORTED: %d\n", stk_is_sorted(*stk));
	ft_printf("\nRANK:\n");
	print_rank(*stk);
	while (!stk_is_sorted(*stk) && count <= 9)
	{
		ft_printf("NOT SORTED\n");
		if ((*stk)->rank > (*stk)->next->rank)
			swap_stk(p, stk_name);
		else
			rotate_stk(p, stk_name);
		print_st(*stk, 'a');
		ft_printf("CURR COUNT: %d\n", count);
		ft_printf("IS SORTED: %d\n", stk_is_sorted(*stk));
		ft_printf("\nRANK:\n");
		print_rank(*stk);
		count++;
	}
	return ;
}
