/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:50:20 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/15 23:39:00 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	ft_push_node(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = new;
		new->previous = p;
	}
}

t_stack	*pop_first(t_stack **top)
{
	t_stack	*node;

	if (!top || !*top)
		return (NULL);
	node = *top;
	(*top)->next->previous = NULL;
	*top = (*top)->next;
	node->next = NULL;
	node->previous = NULL;
}

void	rotate(t_stack	**st)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!st || !*st || !(*st)->next)
		return ;
	first = *st;
	second = (*st)->next;
	last = *st;
	while (last->next)
		last = last->next;
	(*st) = second;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

t_stack	*swap_top(t_stack **st)
{
	int	content;

	if (!st || !*st || !(*st)->next)
		return (NULL);
	content = (*st)->content;
	(*st)->content = (*st)->next->content;
	(*st)->next->content = content;
}
