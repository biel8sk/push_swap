/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:50:20 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/26 02:05:47 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->rank = 0;
	new->pos = 0;
	new->chunk = 0;
	new->content = content;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	ft_push_node(t_stack **lst, t_stack *new)
{
	new->previous = NULL;
	if (!*lst)
		new->next = NULL;
	else
	{
		new->next = *lst;
		(*lst)->previous = new;
	}
	*lst = new;
}

void	stack_clear(t_stack **st)
{
	t_stack	*tmp;

	if (!st || !*st)
		return ;
	while (*st)
	{
		tmp = *st;
		*st = (*st)->next;
		free(tmp);
	}
	*st = NULL;
}

int	stack_contains(int element, t_stack *st)
{
	while (st)
	{
		if (element == st->content)
			return (1);
		st = st->next;
	}
	return (0);
}

void	print_st(t_stack *stk, char stack)
{
	ft_printfd(2, "stack %c: ", stack);
	while (stk)
	{
		ft_printfd(2, "%d -> ", stk->content);
		stk = stk->next;
	}
	ft_putstr_fd("\n", 2);
}
